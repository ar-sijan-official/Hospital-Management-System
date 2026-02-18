#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    bool isEmergency;
};

struct Node {
    Patient data;
    Node* next;
};

class HospitalSystem {
private:
    Node *head, *frontNormal, *rearNormal, *frontUrgent, *rearUrgent, *historyTop;
    const string filename = "patient_data.txt";

public:
    HospitalSystem() {
        head = frontNormal = rearNormal = frontUrgent = rearUrgent = historyTop = NULL;
        loadFromFile(); 
    }

    void registerPatient(int id, string name, int age, bool emergency, bool save = true) {
        Patient p = {id, name, age, emergency};
        Node* newNode = new Node{p, NULL};

        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        
        Node* qNode = new Node{p, NULL};
        if (emergency) {
            if (!rearUrgent) frontUrgent = rearUrgent = qNode;
            else { rearUrgent->next = qNode; rearUrgent = qNode; }
        } else {
            if (!rearNormal) frontNormal = rearNormal = qNode;
            else { rearNormal->next = qNode; rearNormal = qNode; }
        }

        if(save) {
            saveToFile();
            cout << "\n[✔] Patient " << name << " registered and saved to storage!";
        }
    }

    void servePatient() {
        Node* temp = NULL;
        if (frontUrgent) {
            temp = frontUrgent;
            frontUrgent = frontUrgent->next;
            if (!frontUrgent) rearUrgent = NULL;
        } 
        else if (frontNormal) {
            temp = frontNormal;
            frontNormal = frontNormal->next;
            if (!frontNormal) rearNormal = NULL;
        } 
        else {
            cout << "\n[!] No patients waiting in the queue." << endl;
            return;
        }
        cout << "\n>>> Currently Treating: " << temp->data.name << " (ID: " << temp->data.id << ")" << endl;
        temp->next = historyTop;
        historyTop = temp;
    }

    void showLastTreated() {
        if (!historyTop) cout << "\n[!] No treatment history available." << endl;
        else {
            cout << "\n--- MOST RECENT TREATMENT ---" << endl;
            cout << "Name: " << historyTop->data.name << " | ID: " << historyTop->data.id << endl;
        }
    }

    void displayRegistry() {
        if (!head) { cout << "\n[!] Registry is currently empty." << endl; return; }
        cout << "\n+------+----------------------+-----+------------+" << endl;
        cout << "|  ID  |      PATIENT NAME    | AGE |   STATUS   |" << endl;
        cout << "+------+----------------------+-----+------------+" << endl;
        Node* temp = head;
        while (temp) {
            cout << "| " << left << setw(4) << temp->data.id << " | " << setw(20) << temp->data.name 
                 << " | " << setw(3) << temp->data.age << " | " << setw(10) 
                 << (temp->data.isEmergency ? "EMERGENCY" : "NORMAL") << " |" << endl;
            temp = temp->next;
        }
        cout << "+------+----------------------+-----+------------+" << endl;
    }

    void saveToFile() {
        ofstream out(filename);
        Node* temp = head;
        while(temp) {
            out << temp->data.id << " " << temp->data.name << " " << temp->data.age << " " << temp->data.isEmergency << endl;
            temp = temp->next;
        }
        out.close();
    }

    void loadFromFile() {
        ifstream in(filename);
        int id, age; string name; bool em;
        while(in >> id >> name >> age >> em) {
            registerPatient(id, name, age, em, false);
        }
        in.close();
    }
};

#endif