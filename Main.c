#define _CRT_SECURE_NO_WARNINGS
#include "Fleetdb.h"

void main() {

	//Variables
	int userChoice;

	//Menu
	do {
		printf("------------------------------------\n");
		printf("Welcome to Machinery Management Ltd. fleet manamgement system\n");
		printf("Please enter the corresponding number:\n");
		printf("1) Add machine \n");
		printf("2) Display all machines to screen\n");
		printf("3) Display machines details\n");
		printf("4) Update a machine's details\n");
		printf("5) Delete machine\n");
		printf("6) Generate statistics\n");
		printf("7) Print all machine details into a report file\n");
		printf("8) List all the machinery in order of current valuation\n");
		printf("-1) Exit\n");
		printf("------------------------------------\n");
		scanf("%d", userChoice);

		switch (userChoice) {
		case 1:
			//add machine 
			break;
		case 2:
			//display all machine 
			break;
		case 3:
			//display machine details 
			break;
		case 4:
			//update machine 
			break;
		case 5:
			//delete machine
			break;
		case 6:
			//generate stats 
			break;
		case 7:
			//print machine details to report
			break;
		case 8:
			//order machines by value 
			break;
		default:
			printf("Invalid choice please try again.\n");
		}
	} while (!userChoice);
}