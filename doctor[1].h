#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>

using namespace std;

class DoctorManager {
public:
    void suggestDoctor() {
        int choice;
        cout << "\n--- DOCTOR SUGGESTION SYSTEM ---" << endl;
        cout << "Select Health Issue:\n[1] Heart/Chest\n[2] Brain/Nerves\n[3] Child Care\n[4] General Fever/Cold\nChoice: ";
        cin >> choice;

        cout << "\n+----------------------+----------------------+" << endl;
        cout << "|      DEPARTMENT      |    SUGGESTED DOCTOR  |" << endl;
        cout << "+----------------------+----------------------+" << endl;
        
        switch(choice) {
            case 1: cout << "| Cardiology           | Dr. Sarah Jenkins    |" << endl; break;
            case 2: cout << "| Neurology            | Dr. Victor Fries     |" << endl; break;
            case 3: cout << "| Pediatrics           | Dr. Maya Angelou     |" << endl; break;
            case 4: cout << "| General Physician    | Dr. John Watson      |" << endl; break;
            default: cout << "| Invalid Option       | N/A                  |" << endl; break;
        }
        cout << "+----------------------+----------------------+" << endl;
    }
};

#endif