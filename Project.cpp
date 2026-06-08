#include <iostream>
#include<iomanip> // For Customized Output
#include<windows.h> // For cls Function
#include <string>

using namespace std;

// Global Variables

int password = 123; //admin password

// Maximum records we can store
const int max_vehicles = 50;
const int max_drivers = 50;

// Vehicle Data
string vehicleID[max_vehicles];
string vehicleModels[max_vehicles];
int vehicleYears[max_vehicles];
int vehicleCount = 0;

// Driver Data
string driverID[max_drivers];
string driverNames[max_drivers];
int driverAges[max_drivers];
int driverCount = 0;

// Functions Declaraton

void Vehicle();
void addVehicle();
void removeVehicle();
void searchVehicle();
void editVehicle();
void showVehicles();
void Driver();
void addDriver();
void removeDriver();
void searchDriver();
void editDriver();
void showDrivers();
void admin();

void admin(){ // admin function

	int choice, password_check, check;

	again:
	system("cls"); // Clear Screen Funtion
	cout<< "Enter Password: ";
	cin>> password_check;
	if( password == password_check ){

		while(1){
					
			system("cls");
			cout<< "1. Drivers" << endl;
			cout<< "2. Vehicle" << endl;
			cout<< "3. Go Back" << endl;
			cout<< "Enter a Number: ";
			cin>> check;

			switch( check ){

				case 1:
					Driver(); // Calling Driver Function
					break;
				case 2:
					Vehicle(); // Calling Vehicle Function
					break;
				case 3:
					system("cls");
					return;
				default:
					system("cls");
					cout<< "INVALID INPUT!" << endl;
					Sleep(1000);
			}
		}
	}
	else{
		
		cout<< "Wrong Password" << endl;
		Sleep(1000);
		goto again;
	}
}

void Vehicle(){
	
	int check;
	
	while(1){

		system("cls");
		cout<< "1. Add Vehicle" << endl;
		cout<< "2. Edit Vehicle" << endl;
		cout<< "3. Search Vehicle" << endl;
		cout<< "4. Show Vehicle" << endl;
		cout<< "5. Remove Vehicle" << endl;
		cout<< "6. Go Back." << endl;
		cout<< "Enter a Number: ";
		cin>> check;

		switch( check ){
			
			case 1:
				system("cls");
				addVehicle(); // Calling addVehicle Function
				break;
			case 2:
				system("cls");
				editVehicle(); // Calling editVehicle Function
				break;
			case 3:
				system("cls");
				searchVehicle(); // Calling searchVehicle Function
				break;
			case 4:
				system("cls");
				showVehicles(); // Calling showVehicles Function
				break;
			case 5:
				system("cls");
				removeVehicle(); // Calling removeVehicle Function
				break;
			case 6:
				system("cls");
				return;
			default:
				system("cls");
				cout<< "INVALID INPUT!";
				Sleep(1000);
		}
	}
}

void addVehicle(){ // To Add Vehicle

    if (vehicleCount >= max_vehicles) {
    	
        cout << "Cannot add more vehicles!\n";
        return;
    }

    cout << "Enter Vehicle ID: ";
    cin >> vehicleID[vehicleCount];
    cout << "Enter Model: ";
    cin >> vehicleModels[vehicleCount];
    cout << "Enter Year: ";
    cin >> vehicleYears[vehicleCount];

    vehicleCount++;
    cout << "Vehicle added successfully!\n";
}

void searchVehicle(){ // To Search Vehicle

    string id;
    cout << "Enter Vehicle ID to search: ";
    cin >> id;

    for (int i = 0; i < vehicleCount; i++){
    	
        if (vehicleID[i] == id){
            cout << "Vehicle Found:\n";
            cout << "ID: " << vehicleID[i] << " | Model: " << vehicleModels[i] << " | Year: " << vehicleYears[i] << "\n";
            return;
        }
        else{
        	
        	cout << "Vehicle not found!\n";
        	Sleep(2000);
		}
    }
}

void editVehicle() { // Edit Vehicle

    string id;
    cout << "Enter Vehicle ID to edit: ";
    cin >> id;

    for (int i = 0; i < vehicleCount; i++) {
    	
        if (vehicleID[i] == id) {
        	
            cout << "Enter new Model: ";
            cin >> vehicleModels[i];
            cout << "Enter new Year: ";
            cin >> vehicleYears[i];
            cout << "Vehicle updated successfully!\n";
            return;
        }
        else{
        	
        	cout << "Vehicle not found!\n";
        	Sleep(2000);
		}
    }
}

void removeVehicle() { // To Remove Vehicle

    string id;
    cout << "Enter Vehicle ID to remove: ";
    cin >> id;

    for (int i = 0; i < vehicleCount; i++) {
    	
        if (vehicleID[i] == id) {
        	
            for (int j = i; j < vehicleCount - 1; j++) {
            	
                vehicleID[j] = vehicleID[j + 1];
                vehicleModels[j] = vehicleModels[j + 1];
                vehicleYears[j] = vehicleYears[j + 1];
            }
            vehicleCount--;
            cout << "Vehicle removed successfully!\n";
            return;
        }
        else{
        	
        	cout << "Vehicle not found!\n";
        	Sleep(2000);
		}
    }
}

void showVehicles() { // To Display vehicles

	cout<< vehicleCount;
	
    if( vehicleCount == 0 ){
    	
    	cout<< "No Vehicles Available." << endl;
    	return;
	}

    cout << "ID\tModel\tYear\n";
    cout << "-------------------------\n";
    for (int i = 0; i < vehicleCount; i++) {
    	
        cout << vehicleID[i] << "\t" << vehicleModels[i] << "\t" << vehicleYears[i] << "\n";
    }
}

void Driver(){
	
	int check;
	
	while(1){
		
		system("cls");// Clear Screen Funtion
		cout<< "1. Add Driver" << endl;
		cout<< "2. Edit Driver" << endl;
		cout<< "3. Search Driver" << endl;
		cout<< "4. Show Driver" << endl;
		cout<< "5. Remove Driver" << endl;
		cout<< "6. Go Back." << endl;
		cout<< "Enter a Number: ";
		cin>> check;

		switch( check ){
			
			case 1:
				system("cls");
				addDriver(); // Calling addDriver Function
				break;
			case 2:
				system("cls");
				editDriver(); // Calling editDriver Function
				break;
			case 3:
				system("cls");
				searchDriver(); // Calling searchDriver Function
				break;
			case 4:
				system("cls");
				showDrivers(); // Calling showDrivers Function
				break;
			case 5:
				system("cls");
				removeDriver(); // Calling removeDriver Function
				break;
			case 6:
				system("cls");
				return;
			default:
				system("cls");
				cout<< "INVALID INPUT!";
				Sleep(1000);
		}
	}
}

void editDriver() {// To Edit Driver

    string id;
    cout << "Enter Driver ID to edit: ";
    cin >> id;

    for (int i = 0; i < driverCount; i++) {
    	
        if (driverID[i] == id) {
        	
            cout << "Enter new Name: ";
            cin >> driverNames[i];
            cout << "Enter new Age: ";
            cin >> driverAges[i];
            cout << "Driver updated successfully!\n";
            return;
        }
        else{
        	
        	cout << "Driver not found!\n";
        	Sleep(2000);
		}
    }
}

void addDriver() { // To Add Driver

    if (driverCount >= max_drivers) {
    	
        cout << "Cannot add more drivers!\n";
        return;
    }

    cout << "Enter Driver ID: ";
    cin >> driverID[driverCount];
    cout << "Enter Name: ";
    cin >> driverNames[driverCount];
    cout << "Enter Age: ";
    cin >> driverAges[driverCount];

    driverCount++;
    cout << "Driver added successfully!\n";
}

void searchDriver() { // To Search Driver

    string id;
    cout << "Enter Driver ID to search: ";
    cin >> id;

    for (int i = 0; i < driverCount; i++) {
    	
        if (driverID[i] == id) {
        	
            cout << "Driver Found:\n";
            cout << "ID: " << driverID[i] << " | Name: " << driverNames[i] << " | Age: " << driverAges[i] << "\n";
            return;
        }
        else{
        	
        	cout << "Driver not found!\n";
        	Sleep(2000);
		}
    }
}

void removeDriver() {// To Remove Driver

    string id;
    cout << "Enter Driver ID to remove: ";
    cin >> id;

    for (int i = 0; i < driverCount; i++) {
    	
        if (driverID[i] == id) {
        	
            for (int j = i; j < driverCount - 1; j++) {
            	
                driverID[j] = driverID[j + 1];
                driverNames[j] = driverNames[j + 1];
                driverAges[j] = driverAges[j + 1];
            }
            driverCount--;
            cout << "Driver removed successfully!\n";
            return;
        }
        else{
        	
        	cout << "Driver not found!\n";
        	Sleep(2000);
		}
    }
}

void showDrivers() { // to Display Drivers

	system("cls");
    if (driverCount == 0) {
    	
        cout << "No drivers available.\n";
        cout.flush(); // Explicitly flush the output buffer
        Sleep(2000); 
        return;
    }

    cout << "ID\tName\tAge\n";
    cout << "-------------------------\n";
    for (int i = 0; i < driverCount; i++) {
    	
        cout << driverID[i] << "\t" << driverNames[i] << "\t" << driverAges[i] << "\n";
    }
    Sleep(2000); 
}

int main(){ // main function

	int choose;
	cout<< endl << endl;
	cout<< setw(50) << " " << "Vehicle Management System" << endl << endl << endl;
	cout<< setfill('=') << setw(121) << " " << endl << endl;
	
	Sleep(2000);

	while(1){// infinity loop

		system("cls");
		cout<< "1. Admin " << endl;
		cout<< "2. Exit" << endl;
		cout<< "Select an Number: ";
		cin>> choose;

		switch( choose ){

			case 1:
				admin(); // Calling admin Function
				break;
			case 2:
				return 0;
			default:
				system("cls");
				cout<< "INVALID INPUT!" << endl;
				Sleep(1000);
		}
	}
}
