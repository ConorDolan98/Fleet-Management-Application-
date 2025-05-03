#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "Fleetdb.h"

int menu();

void main() {
	fleetMachineryDB* head = NULL; //initalises head pointer to NULL
	
	//login feature
	char userAccess[10];

	if (!login(userAccess)) {
		printf("Login failed.\n");
		return;
	}

	
	//Read in fleet.txt file
	readFromFile(&head);

	//Variables
	int userChoice=0;
	//Menu();
	do {
		userChoice = menu();

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
			if (strcmp(userAccess, "admin1") != 0) {
				printf("Access denied. Admin only.\n");
				break;
			}
			printf("You selected display machine details.\n\n");
			displayMachineDetails(head);
			break;
		case 4:
			//update machine 
			if (strcmp(userAccess, "admin1") != 0) {
				printf("Access denied. Admin only.\n");
				break;
			}
			printf("You selected update a machines details.\n\n");
			updateMachine(head);
			break;
		case 5:
			//delete machine
			printf("You selected delete a machine.\n\n");
			deleteMachine(&head);
			break;
		case 6:
			//generate stats 
			printf("You selected generate machine statistics.\n\n");
			generateStats(head);
			break;
		case 7:
			//print machine details to report
			printf("You selected print machine details to report.\n\n");
			machineReport(head);
			break;
		case -1:
			//exit program
			printf("Saving on exit...\n");
			machineReport(head);

			break;
		default:
			printf("Invalid choice please try again.\n");
		}
	} while (userChoice != -1);
	return 0;
}

int menu() {
	int choice;
	printf("--------------------------------------------------\n");
	printf("Welcome to Machinery Management Ltd. fleet manamgement system\n");
	printf("Please enter the corresponding number:\n");
	printf("1) Add machine \n");
	printf("2) Display all machines to screen\n");
	printf("3) Display machines details (Admin Access)\n");
	printf("4) Update a machine's details (Admin Access)\n");
	printf("5) Delete machine\n");
	printf("6) Generate statistics\n");
	printf("7) Print all machine details into a report file\n");
	printf("-1) Exit\n");
	printf("--------------------------------------------------\n");
	printf("Enter Choice: ");
	scanf("%d", &choice);
	printf("\n");
	return choice;
}

int login(char* userAccess) {
	//Variables
	Login databaseUsers[3];
	char userName[10];
	char passWord[10];

	FILE* file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return 1;
	}

	//Read in the file
	for (int i = 0; i < 3; i++) {
		char line[30];
		fgets(line, sizeof(line), file);
		sscanf(line, "%s %s", databaseUsers[i].userName, databaseUsers[i].passWord);
	}
	fclose(file);

	printf("Please enter your username: ");
	scanf("%s", userName);

	printf("Please enter your password: ");
	scanf("%s", passWord);

	//Check if the user is in the database
	for (int i = 0; i < 3; i++) {
		if (strcmp(userName, databaseUsers[i].userName) == 0 && 
			strcmp(passWord, databaseUsers[i].passWord) == 0) {
			printf("Login successful.\n");
			strcpy(userAccess, userName);
			return 1;
		}
	}
	printf("Login failed. Invalid details.\n");
	return 0;
}

