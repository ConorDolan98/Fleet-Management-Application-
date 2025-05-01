#pragma once
#ifndef fleetdb
#define fleetdb

typedef struct
{
	char userName[30];
	char passWord[30];
}Login;

typedef struct fleetMachineryDB
{
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
	char breakdowns[50];

	struct fleetMachineryDB* next; //points at next node  - linked list
}fleetMachineryDB;

// Function prototypes
void addMachine(fleetMachineryDB** head);
void displayAll(fleetMachineryDB* head);
void displayMachineDetails(fleetMachineryDB* head);
void updateMachine(fleetMachineryDB* head);


#endif // !fleetdb