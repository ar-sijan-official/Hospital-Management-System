#include <iostream>
#include <string>
#include <cstdlib>
#include "patient.h"
#include "doctor.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseSystem() {
    cout << "\nPress Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();
}

void printTitle() {
    cout << "\033[1;32m"; 
    cout << "################################################################################" << endl;
    cout << "  _    _  ____   _____ _____ _____ _______       _      " << endl;
    cout << " | |  | |/ __ \\ / ____|  __ \\_   _|__   __|/\\   | |     " << endl;
    cout << " | |__| | |  | | (___ | |__) || |    | |  /  \\  | |     " << endl;
    cout << " |  __  | |  | |\\___ \\|  ___/ | |    | | / /\\ \\ | |     " << endl;
    cout << " | |  | | |__| |____) | |    _| |_   | |/ ____ \\| |____ " << endl;
    cout << " |_|  |_|\\____/|_____/|_|   |_____|  |_/_/    \\_\\______|" << endl;
    cout << "\n           TEAM: NAPA EXTRA       " << endl;
    cout << "################################################################################" << endl;
    cout << "\033[0m"; 
}

int main() {
    HospitalSystem hospital;
    DoctorManager doctor;
    int choice, id, age;
    string name;
    bool emergency;

    while (true) {
        clearScreen();
        printTitle();
        
        cout << "\n [1] Register New Patient" << endl;
        cout << " [2] Serve Next Patient (Priority Logic)" << endl;
        cout << " [3] View Last Treated (Stack History)" << endl;
        cout << " [4] View All Registered Patients (Table View)" << endl;
        cout << " [5] Get Doctor Suggestion" << endl;
        cout << " [6] Exit System" << endl;
        cout << "\n Choose Option: ";
        
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(100, '\n'); continue;
        }

        switch (choice) {
            case 1:
                cout << "\n--- Registration ---" << endl;
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Age: "; cin >> age;
                cout << "Emergency (1:Yes / 0:No): "; cin >> emergency;
                hospital.registerPatient(id, name, age, emergency);
                pauseSystem();
                break;
            case 2:
                hospital.servePatient();
                pauseSystem();
                break;
            case 3:
                hospital.showLastTreated();
                pauseSystem();
                break;
            case 4:
                cout << "\n--- FULL HOSPITAL REGISTRY ---" << endl;
                hospital.displayRegistry();
                pauseSystem();
                break;
            case 5:
                doctor.suggestDoctor();
                pauseSystem();
                break;
            case 6:
                return 0;
        }
    }
}