# Design
## Description
This program will allow the user to record when a person exits or enters a study room and will identify when occupancy is full.
## Flow
There will be a menu option that accepts user input to select from four options: add, remove, quit, init. The program will check if a csv file exists and if the data inside matches the formatting necessary. If not, the csv will be created and the user will be prompted to enter a max value, and the amount of people in the room will be initialized to zero. The CSV file will be formatted to be "# of ppl in room, max value". The occupancy will be printed every time a change is made (adding or removing). The changes will be logged in a .txt file. The program will work with an LED light to indicate when max occupancy is reached.
