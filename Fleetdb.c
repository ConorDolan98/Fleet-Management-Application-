#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fleetdb.h"

void addMachine(fleetMachineryDB** head) {
	//Variables
	char chassisNum[30];
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
	scanf("%s", newNode->machineMake);

	printf("Please enter the machines model: \t\t");
	scanf("%s", newNode->machineModel);

	printf("Please enter the machines year: \t\t");
	scanf("%d", &newNode->year);

	printf("Please enter the machines cost: \t\t");
	scanf("%f", &newNode->cost);

	printf("Please enter the machines current value: \t");
	scanf("%f", &newNode->currValue);

	printf("Please enter the machines mileage: \t\t");
	scanf("%d", &newNode->mileage);

	printf("Please enter the machines next service: \t");
	scanf("%d", &newNode->nextService);

	getchar();//clears \n

	printf("Please enter the machines owner name: \t\t");
	scanf("%s", newNode->ownerName);

	//Checks if email contains @ and ends with .com
	//strchr finds the posititon of a char
	do {
		printf("Please enter the machine's owner email: \t");
		scanf("%s", newNode->ownerEmail);

		if (strchr(newNode->ownerEmail, '@') == NULL ||
			strcmp(&newNode->ownerEmail[strlen(newNode->ownerEmail) - 4], ".com") != 0) {
			printf("Invalid email. Must contain '@' and end with '.com'\n");
		}

	} while (strchr(newNode->ownerEmail, '@') == NULL ||
		strcmp(&newNode->ownerEmail[strlen(newNode->ownerEmail) - 4], ".com") != 0);


	printf("Please enter the machines owner phone: \t\t");
	scanf("%s", newNode->ownerPhone);

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
		printf("No machines in the database.\n");
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

				do {
					printf("Please enter the machine's owner email: \t");
					scanf("%s", temp->ownerEmail);

					if (strchr(temp->ownerEmail, '@') == NULL ||
						strcmp(&temp->ownerEmail[strlen(temp->ownerEmail) - 4], ".com") != 0) {
						printf("Invalid email. Must contain '@' and end with '.com'\n");
					}

				} while (strchr(temp->ownerEmail, '@') == NULL ||
					strcmp(&temp->ownerEmail[strlen(temp->ownerEmail) - 4], ".com") != 0);


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

	// Deletes the head node
	if (prev == NULL)	{
		*head = temp->next;
	}
	else {
		prev->next = temp->next;//deleted the node after
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
	char diffMachines[5][30] = { "Tractor", "Excavator", "Roller", "Crane", "Mixer" };
	char breakdownEvents[4][50] = { "Never", "Less than three times", "Less than five times", "More than five times" };
	int machineStats[5][4] = { 0 }; //Initliased at 0
	int total[5] = { 0 };
	int machineTypeArrayIndex = -1, breakdownArrayIndex = -1;
	float percent;

	fleetMachineryDB* temp = head;

	while (temp != NULL) {
		
		//loop finds machine type
		for (int i = 0; i < 5; i++) {
			if (strcmp(temp->machineType, diffMachines[i]) == 0) {
				machineTypeArrayIndex = i;
				break;
			}
		}

		//loop finds breakdown type
		for (int i = 0; i < 4; i++) {
			if (strcmp(temp->breakdowns, breakdownEvents[i]) == 0) {
				breakdownArrayIndex = i;
				break;
			}
		}

		//increments if both machine type and breakdown type is found
		if (machineTypeArrayIndex != -1 && breakdownArrayIndex != -1) {
			machineStats[machineTypeArrayIndex][breakdownArrayIndex]++;
			total[machineTypeArrayIndex]++;
		}
		temp = temp->next;
	}

	//Prints out the statistics
	printf("-------------------Machine Stats------------------\n");
	for (int i = 0; i < 5; i++) {
		printf("Machine Type: %s\n", diffMachines[i]);
		for (int j = 0; j < 4; j++) {
			if (total[i] != 0) {
				percent = ((float)machineStats[i][j] / total[i]) * 100;
			}
			else {
				percent = 0;
			}
			printf("Breakdown Type: %s - Count: %d - Percentage: %.2f%%\n", breakdownEvents[j], machineStats[i][j], percent);
		}
		printf("--------------------------------------------------\n");
	}

}

void machineReport(fleetMachineryDB* head) {
	FILE* file = fopen("fleet.txt", "w");

	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	if (head == NULL) {
		fprintf(file, "No machines in database\n");
	}
	else {
		fleetMachineryDB* temp = head;
		while (temp != NULL) {
			fprintf(file, "%s %s %s %d %.2f %.2f %d %d %s %s %s %s %s\n",
				temp->chassisNum, temp->machineMake, temp->machineModel,
				temp->year, temp->cost, temp->currValue,
				temp->mileage, temp->nextService,
				temp->ownerName, temp->ownerEmail,
				temp->ownerPhone, temp->machineType, temp->breakdowns);
			temp = temp->next;
		}
	}
	fclose(file);
}

void readFromFile(fleetMachineryDB** head) {
	FILE* file = fopen("fleet.txt", "r");
	if (!file) {
		printf("No existing fleet data found.\n");
		return;
	}

	fleetMachineryDB temp;
	while (fscanf(file, "%s %s %s %d %f %f %d %d %s %s %s %s %s",
		temp.chassisNum, temp.machineMake, temp.machineModel,
		&temp.year, &temp.cost, &temp.currValue, &temp.mileage,
		&temp.nextService, temp.ownerName, temp.ownerEmail,
		temp.ownerPhone, temp.machineType, temp.breakdowns) == 13)
	{
		// Allocate memory for a new node
		fleetMachineryDB* newNode = malloc(sizeof(fleetMachineryDB));
		*newNode = temp;  // Copy all fields
		newNode->next = NULL;

		// Insert at end of list
		if (*head == NULL) {
			*head = newNode;
		}
		else {
			fleetMachineryDB* last = *head;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = newNode;
		}
	}

	fclose(file);
	printf("Fleet data loaded from fleet.txt\n");
}
