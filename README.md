# Chaos Hospital Management System

---

## Abstract

Efficient hospital administration is essential for managing patient flow, prioritizing emergency cases, and maintaining structured medical records. The Chaos Hospital Management System (CHMS) is a console-based application developed in C that integrates fundamental data structures such as Linked Lists, Priority Queues, and Stacks. The system ensures emergency case prioritization through triage logic and maintains persistent storage using file handling techniques. This project demonstrates the practical implementation of structured programming and algorithmic design in modeling healthcare workflow systems.

<img width="1696" height="946" alt="Screenshot_২০২৬০২১৮_১০৪৪৫৬-1" src="https://github.com/user-attachments/assets/2a7d5b5a-834b-4c8a-99f9-4b1a7e4493ac" />
---



## 1. Introduction

Hospital environments frequently experience operational challenges including overcrowding, delayed services, and inefficient patient routing. These challenges can negatively impact healthcare delivery.

The objective of this project is to design and implement a structured hospital workflow model that:

- Registers patients dynamically  
- Prioritizes emergency cases 
 
- Tracks treatment history  
- Suggests appropriate medical departments  
- Ensures persistent data storage  

The system emphasizes the application of core data structures in solving real-world service management problems.

---

## 2. System Architecture

The system is organized into the following modules:

1. Patient Registration Module  
2. Priority-Based Triage Module  
3. Treatment History Module  
4. Doctor Suggestion Module  
5. Data Persistence Module  

Each module is implemented using appropriate data structures to maintain efficiency and clarity.

---

## 3. Data Structures and Algorithms

### 3.1 Linked List (Global Patient Registry)

A singly linked list is used to dynamically store patient records without predefined size limitations.

**Time Complexity:**
- Insertion: O(n)  
- Traversal: O(n)

---

### 3.2 Priority Queue (Waiting Room Management)

Patients are ordered according to severity level. Emergency cases are served before routine cases.

**Time Complexity:**
- Insertion: O(n)  
- Deletion (Highest Priority): O(1)

---

### 3.3 Stack (Treatment History)

A stack data structure follows the Last-In, First-Out (LIFO) principle to track recently treated patients.

**Time Complexity:**
- Push: O(1)  
- Pop: O(1)

---

### 3.4 Array of Structures (Doctor Database)

An array-based mapping provides constant-time access to department-specific information.

**Time Complexity:**
- Access: O(1)

---

### 3.5 File Handling (Data Persistence)

Patient data is stored in a `.txt` file using file input/output operations to ensure persistence after program termination.

---

## 4. System Features

- Dynamic patient registration  
- Emergency prioritization through triage logic  
- Doctor recommendation based on symptoms  
- Viewing all registered patients  
- Viewing most recently treated patient  
- Persistent storage of records  

---

## 5. Implementation Details

**Programming Language:** C  

**Concepts Applied:**
- Structures  
- Pointers  
- Dynamic Memory Allocation  
- Linked Lists  
- Priority Queues  
- Stacks  
- File I/O  

The application is implemented as a menu-driven console program.

---

## 6. User Interface Flow

Upon execution, the system provides the following options:

1. Register New Patient  
2. Serve Next Patient (Priority-Based)  
3. View Last Treated Patient  
4. View All Registered Patients  
5. Get Doctor Suggestion  
6. Exit System  

---

## 7. Academic Contribution

This project demonstrates:

- Practical implementation of abstract data structures  
- Real-world system modeling  
- Structured programming methodology  
- Algorithmic problem-solving  

It bridges theoretical computer science concepts with applied healthcare workflow modeling.

---

## 8. Compilation and Execution

```bash
gcc main.c -o hospital
./hospital
