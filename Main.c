#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "Fleetdb.h"

//Variables
int userChoice=0;
int menu();

void main() {
	fleetMachineryDB* head = NULL; //initalises head pointer to NULL

	//Menu
	do {
		menu();

		switch (userChoice) {
		case 1:
			//add machine 
			printf("You selected add machine.\n\n");
			addMachine(&head);
			break;
		case 2:
			//display all machines
			printf("You selected display all machines.\n\n");
			displayAll(head);
			break;
		case 3:
			//display machine details 
			printf("You selected display machine details.\n\n");
			displayMachineDetails(head);
			break;
		case 4:
			//update machine 
			printf("You selected update a machines details.\n\n");
			updateMachine(head);
			break;
		case 5:
			//delete machine
			printf("You selected delete a machine.\n\n");
			deleteMachine();
			break;
		case 6:
			//generate stats 
			printf("You selected generate machine statistics.\n\n");
			machineReport();
			break;
		case 7:
			//print machine details to report
			break;
		case 8:
			//order machines by value 
			break;
		case -1:
			//exit program
			printf("Exiting the program...\n");
			break;
		default:
			printf("Invalid choice please try again.\n");
		}
	} while (userChoice != -1);
	return 0;
}

int menu() {
	printf("--------------------------------------------------\n");
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
	printf("--------------------------------------------------\n");
	printf("Enter Choice: ");
	scanf("%d", &userChoice);
	printf("\n");
}