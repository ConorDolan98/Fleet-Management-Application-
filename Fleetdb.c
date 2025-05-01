#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fleetdb.h"

void addMachine(fleetMachineryDB** head) {
	//Variables
	char chassisNum[30];
	char machineMake[30];
	char machineModel[30];
	int year;
	float cost;
	float currValue;
	int mileage;
	int nextService;
	char ownerName[30];
	char ownerEmail[30];
	char ownerPhone[30];
	char machineType[30];
	char breakdowns[30];
	int typeChoice;
	int breakdownChoice;

	printf("Please enter the machines chassis number: \t");
	scanf("%s", chassisNum);

	getchar(); // clears \n

    // Check for copies - Chassis must be unique
    fleetMachineryDB* copy = *head;
    while (copy != NULL) {
        if (strcmp(copy->chassisNum, chassisNum) == 0) {
            printf("Chassis number is already in database.\n");
            return;
        }
        copy = copy->next;
    }

    // Create new memory instance
	fleetMachineryDB* newNode = malloc(sizeof(fleetMachineryDB));



	strcpy(newNode->chassisNum, chassisNum);
	
	printf("Please enter the machines make: \t\t");
	scanf("%s", machineMake);
	strcpy(newNode->machineMake, machineMake);

	printf("Please enter the machines model: \t\t");
	scanf("%s", machineModel);
	getchar(); // clears \n
	strcpy(newNode->machineModel, machineModel);

	printf("Please enter the machines year: \t\t");
	scanf("%d", &year);
	newNode->year = year;

	printf("Please enter the machines cost: \t\t");
	scanf("%f", &cost);
	newNode->cost = cost;

	printf("Please enter the machines current value: \t");
	scanf("%f", &currValue);
	newNode->currValue = currValue;

	printf("Please enter the machines mileage: \t\t");
	scanf("%d", &mileage);
	newNode->mileage = mileage;

	printf("Please enter the machines next service: \t");
	scanf("%d", &nextService);
	newNode->nextService = nextService;

	getchar();//clears \n

	printf("Please enter the machines owner name: \t\t");
	scanf("%s", ownerName);
	strcpy(newNode->ownerName, ownerName);

	printf("Please enter the machines owner email: \t\t");
	scanf("%s", ownerEmail);
	strcpy(newNode->ownerEmail, ownerEmail);

	printf("Please enter the machines owner phone: \t\t");
	scanf("%s", ownerPhone);
	strcpy(newNode->ownerPhone, ownerPhone);

	do {
		printf("Select the machine type : 1) Tractor 2) Excavator 3) Roller 4) Crane 5) Mixer\n");
		printf("Enter choice (1-5): ");
		scanf("%d", &typeChoice);
	} while (typeChoice < 1 || typeChoice > 5);
	//Match the type to a string
	switch (typeChoice) {
	case 1: 
		strcpy(machineType, "Tractor"); 
		break;
	case 2: 
		strcpy(machineType, "Excavator"); 
		break;
	case 3: 
		strcpy(machineType, "Roller"); 
		break;
	case 4: 
		strcpy(machineType, "Crane"); 
		break;
	case 5: strcpy(machineType, "Mixer"); 
		break;
	default:
		printf("Invalid choice, try again");
	}
	strcpy(newNode->machineType, machineType);

	do {
		printf("Please enter the machines breakdowns: \n1) Never 2) Less than three times 3) Less than five times 4) More than five times\n");
		printf("Enter choice (1-4): ");
		scanf("%d", &breakdownChoice);
	} while (breakdownChoice < 1 || breakdownChoice > 4);

	switch (breakdownChoice) {
		case 1: 
			strcpy(breakdowns, "Never"); 
			break;
		case 2: 
			strcpy(breakdowns, "Less than three times"); 
			break;
		case 3: 
			strcpy(breakdowns, "Less than five times"); 
			break;
		case 4: 
			strcpy(breakdowns, "More than five times"); 
			break;
		default:
			printf("Invalid choice, try again");
		}
	strcpy(newNode->breakdowns, breakdowns);

	// Orders chassis as its added
	fleetMachineryDB* current = *head; //dictates where to stop
	fleetMachineryDB* previous = NULL; //dictates where to insert

	while (current != NULL && strcmp(newNode->chassisNum, current->chassisNum) > 0) {
		previous = current;
		current = current->next;
	}

	if (previous == NULL) {
		newNode->next = *head;
		*head = newNode;
	}
	else {
		newNode->next = current;
		previous->next = newNode;
	}

	printf("New machine added to the database.\n");
}

void displayAll(fleetMachineryDB* head) {
	
	if (head == NULL) 
	{
		printf("No machines in the database.\n");
		return;
	}
	else 
	{
		fleetMachineryDB* temp = head;
		while (temp != NULL) {
			printf("--------------------------------------------------\n");
			printf("Chassis Number is : %s\n", temp->chassisNum);
			printf("Machine Make is : %s\n", temp->machineMake);
			printf("Machine Model is : %s\n", temp->machineModel);
			printf("Machine Year is : %d\n", temp->year);
			printf("Machine Cost is : %.2f\n", temp->cost);
			printf("Machine Current Value is : %.2f\n", temp->currValue);
			printf("Machine Mileage is : %d\n", temp->mileage);
			printf("Machine Next Service is : %d\n", temp->nextService);
			printf("Machine Owner Name is : %s\n", temp->ownerName);
			printf("Machine Owner Email is : %s\n", temp->ownerEmail);
			printf("Machine Owner Phone is : %s\n", temp->ownerPhone);
			printf("Machine Type is : %s\n", temp->machineType);
			printf("Machine Breakdowns are : %s\n", temp->breakdowns);
			printf("--------------------------------------------------\n");

			temp = temp->next; //moves to the next node
		}
	}
}

void displayMachineDetails() {
	return 0;
}

void updateMachine() {
	return 0;
}

void deleteMachine() {
	return 0;
}

void machineReport() {
	return 0;
}