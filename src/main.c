#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 17

int main(int argc, char* argv[]) {

	// LED set up
	gpioInitialise();
	gpioSetMode(PIN, PI_OUTPUT);

	// Initialise variables
	int count = 0;	// Starting amt of people in room
	int choice = 0;
	
	printf("1: Add\n2: Remove\n3: Quit\n");
	// Input
	while(choice != 3) {

		scanf("%d", &choice);

		// Add & Remove
		if(choice == 1) {
			if(count < 5) {
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
			printf("Invalid choice.\n");
			}

		// LED Monitor
		if(count == 5) {
			gpioWrite(PIN, 1);
		} else {
			gpioWrite(PIN, 0);
		}
	} // End of while loop

	gpioWrite(PIN, 0);	// Turn LED off
	gpioTerminate();
	return 0;
}
