#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 17

int main(int argc, char* argv[]) {
	
	// File creation
	FILE* fp;			// Initialise file pointer
	fp = fopen("output.txt", "w");	// Create or overwrite an output file
	if(fp == NULL) {
		fprintf(stderr, "Failed to create a file.\n");
		return 1;
	}

	// LED set up
	gpioInitialise();
	gpioSetMode(PIN, PI_OUTPUT);

	// Initialise variables
	int count = 0;	// Starting amt of people in room
	int choice = 0;
	unsigned int max = 0;
	printf("Enter max capacity of room:\n");
	scanf("%d", &max);

	// Formatting
	fprintf(fp, "Current Occupancy\tSystem Status\tFull Indicator LED\n");
	fprintf(fp, "%d/%d\t\t\t\t\tSPACE AVAILABLE\tOFF\n", count, max);
	printf("1: Add\n2: Remove\n3: Quit\n");

	// Input
	while(choice != 3) {

		scanf("%d", &choice);

		// Add & Remove
		if(choice == 1) {
			if(count < max) {
			count++;
			} else {
				printf("Room is full!\n");
				}
		} else if (choice ==  2) {
			if(count > 0){
			count--;
			} else {
				printf("Room is empty!\n");
				}
		} else if (choice != 3) {
			printf("Invalid choice, terminating program.\n");
			choice = 3;
			}

		// LED Monitor
		if(count == max) {
			gpioWrite(PIN, 1);
		} else {
			gpioWrite(PIN, 0);
		}
		// File output update
		if(count < max) {
			fprintf(fp, "%d/%d\t\t\t\t\tSPACE AVAILABLE\tOFF\n", count, max);
		} else {
			fprintf(fp, "%d/%d\t\t\t\t\tROOM FULL\t\tON\n", count, max);
		}
	} // End of while loop

	gpioWrite(PIN, 0);	// Turn LED off
	gpioTerminate();
	fclose(fp);		// Close file
	return 0;
}
