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

	//Inserts the node at beginning
	if (previous == NULL) {
		newNode->next = *head;
		*head = newNode;
	}

	//Inserts a node inbetween nodes
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

void displayMachineDetails(fleetMachineryDB* head) {

	//Variables
	char searchChassis[30];

	if (head == NULL) {
		printf("No machines in the database.\n");
		return;
	}
	else {
		printf("Please enter the machines chassis number: \t");
		scanf("%s", searchChassis);

		fleetMachineryDB* temp = head;

		while (temp != NULL) {
			if (strcmp(temp->chassisNum, searchChassis) == 0) {
				printf("-------------------Machine Details----------------\n");
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
				return;
			}
			temp = temp->next;
		}

		printf("Machine with chassis number '%s' not found.\n", searchChassis);
	}
}

void updateMachine(fleetMachineryDB* head) {

	//Variables
	char searchChassis[30];
	int typeChoice;
	int breakdownChoice;

	if (head == NULL) {
		printf("No machines in the database.");
		return;
	}
	else {
		printf("Please enter the machines chassis number: \t");
		scanf("%s", searchChassis);

		getchar(); // clears \n

		fleetMachineryDB* temp = head;
		while (temp != NULL) {
			if (strcmp(temp->chassisNum, searchChassis) == 0) {
				printf("Machine found. Update its details.\n");

				printf("Enter the machines make: \t\t");
				scanf("%s", temp->machineMake);

				printf("Enter the machines model: \t\t");
				scanf("%s", temp->machineModel);

				printf("Enter the machines year: \t\t");
				scanf("%d", &temp->year);

				printf("Enter the machines cost: \t\t");
				scanf("%f", &temp->cost);

				printf("Enter the machines current value: \t");
				scanf("%f", &temp->currValue);

				printf("Enter the machines mileage: \t\t");
				scanf("%d", &temp->mileage);

				printf("Enter the machines next service: \t");
				scanf("%d", &temp->nextService);

				printf("Enter the machines owner name: \t\t");
				scanf("%s", temp->ownerName);

				printf("Enter the machines owner email: \t");
				scanf("%s", temp->ownerEmail);

				printf("Enter the machines owner phone: \t");
				scanf("%s", temp->ownerPhone);

				do {
					printf("Enter the machines type: 1) Tractor 2) Excavator 3) Roller 4) Crane 5) Mixer\n");
					//scanf("%s", temp->machineType);
					scanf("%d", &typeChoice);
				} while (typeChoice < 1 || typeChoice > 5);

				switch (typeChoice) {
				case 1:
					strcpy(temp->machineType, "Tractor");
					break;
				case 2:
					strcpy(temp->machineType, "Excavator");
					break;
				case 3:
					strcpy(temp->machineType, "Roller");
					break;
				case 4:
					strcpy(temp->machineType, "Crane");
					break;
				case 5:
					strcpy(temp->machineType, "Mixer");
					break;
				default:
					printf("Invalid choice, try again");
				}

				do {
					printf("Enter the machines breakdowns: \n1) Never 2) Less than three times 3) Less than five times 4) More than five times\n");
					scanf("%d", &breakdownChoice);

					switch (breakdownChoice) {
					case 1:
						strcpy(temp->breakdowns, "Never");
						break;
					case 2:
						strcpy(temp->breakdowns, "Less than three times");
						break;
					case 3:
						strcpy(temp->breakdowns, "Less than five times");
						break;
					case 4:
						strcpy(temp->breakdowns, "More than five times");
						break;
					default:
						printf("Invalid choice, try again");
					}
				} while (breakdownChoice < 1 || breakdownChoice > 4);

				printf("Machine details updated successfully.\n");
				return;
			}
			temp = temp->next;	
		}
	printf("Machine with chassis number %s not found.\n", searchChassis);
	}
}

void deleteMachine(fleetMachineryDB** head) {
	
	//Variables
	char searchChassis[30];

	if (*head == NULL) {
		printf("No machines in the database.\n");
		return;
	}

	printf("Enter the chassis number to delete: ");
	scanf("%s", searchChassis);

	fleetMachineryDB* temp = *head;
	fleetMachineryDB* prev = NULL;

	while (temp != NULL && strcmp(temp->chassisNum, searchChassis) != 0) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Machine with chassis number %s not found.\n", searchChassis);
		return;
	}

	free(temp); //frees up the data

	printf("Machine with chassis number %s deleted successfully.\n", searchChassis);

}

void generateStats(fleetMachineryDB* head) {
	if (head == NULL) {
		printf("No machines in the database.\n");
		return;
	}

	//Variables
	int machineTypeArrayIndex = -1, breakdownArrayIndex = -1;
	//Initialising arrays
	int stats[5][4] = { 0 };
	int typeTotals[5] = { 0 };
	float percent;

	// Fill the stats matrix
	fleetMachineryDB* temp = head;
	while (temp != NULL) {

		// Machine Type Index
		if (strcmp(temp->machineType, "Tractor") == 0) {
			machineTypeArrayIndex = 0;
		}
		else if (strcmp(temp->machineType, "Excavator") == 0) {
			machineTypeArrayIndex = 1;
		}
		else if (strcmp(temp->machineType, "Roller") == 0) {
			machineTypeArrayIndex = 2;
		}
		else if (strcmp(temp->machineType, "Crane") == 0) {
			machineTypeArrayIndex = 3;
		}
		else if (strcmp(temp->machineType, "Mixer") == 0) {
			machineTypeArrayIndex = 4;
		}

		// Breakdown Index
		if (strcmp(temp->breakdowns, "Never") == 0) {
			breakdownArrayIndex = 0;
		}
		else if (strcmp(temp->breakdowns, "Less than three times") == 0) {
			breakdownArrayIndex = 1;
		}
		else if (strcmp(temp->breakdowns, "Less than five times") == 0) {
			breakdownArrayIndex = 2;
		}
		else if (strcmp(temp->breakdowns, "More than five times") == 0) {
			breakdownArrayIndex = 3;
		}

		if (machineTypeArrayIndex != -1 && breakdownArrayIndex != -1) {
			stats[machineTypeArrayIndex][breakdownArrayIndex]++;
			typeTotals[machineTypeArrayIndex]++;
		}

		temp = temp->next;
	}

	// Print results
	// Outer loop prints machine type
	for (int type = 0; type < 5; type++) {
		if (typeTotals[type] = 0) {

			// Print machine type label
			switch (type) {
			case 0:
				printf("\nMachine Type: Tractor\n");
				break;
			case 1:
				printf("\nMachine Type: Excavator\n");
				break;
			case 2:
				printf("\nMachine Type: Roller\n");
				break;
			case 3:
				printf("\nMachine Type: Crane\n");
				break;
			case 4:
				printf("\nMachine Type: Mixer\n");
				break;
			}
		}
		
		//inner loop prints %
		for (int breakdowns = 0; breakdowns < 4; breakdowns++) {
			percent = (stats[type][breakdowns] * 100.0f) / typeTotals[type];

			switch (breakdowns) {
			case 0: 
				printf("  Never:\t\t\t%.2f%%\n", percent);//to output a percentage extra %% is required at end
				break;
			case 1: 
				printf("  Less than three times:\t%.2f%%\n", percent); 
				break;
			case 2: 
				printf("  Less than five times:\t\t%.2f%%\n", percent); 
				break;
			case 3: 
				printf("  More than five times:\t\t%.2f%%\n", percent); 
				break;
			}
		}
	}
}

void machineReport() {

}