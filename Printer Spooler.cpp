/*
PROBLEM STATEMENT:
Printer Spooler (Circular Queue):
In a multi-user environment, printers often use a circular queue to manage print jobs.
Each print job is added to the queue, and the printer processes them in the order they arrive.
Once a print job is completed, it moves out of the queue, and the next job is processed,
efficiently managing the flow of print tasks. Implement the Printer Spooler system
using a circular queue without using built-in queues.
*/

#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

class PrinterSpooler {
private:
    string jobQueue[SIZE];
    int front, rear;

public:
    PrinterSpooler() {
        front = -1;
        rear = -1;
    }

    int isFull() {
        return ((rear + 1) % SIZE == front);
    }

    int isEmpty() {
        return (front == -1 && rear == -1);
    }

    void addJob(string job) {
        if (isFull()) {
            cout << "Spooler is full! Cannot add job " << job <<endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        jobQueue[rear] = job;
        cout << "Print job " << job << " added to spooler" << endl;
    }

    void processJob() {
        if (isEmpty()) {
            cout << "Spooler is empty! No jobs to process" << endl;
            return;
        }
        cout << "Processed print job " << jobQueue[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void displayJobs() {
        if (isEmpty()) {
            cout << "No print jobs in spooler" << endl;
            return;
        }
        cout << "Current print jobs in spooler: ";
        int i = front;
        while (true) {
            cout << jobQueue[i];
            if (i == rear) break;
            cout << " , ";
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    PrinterSpooler spooler;
    int choice;
    string jobName;
    char cont = 'y';

    while (cont == 'y') {
        cout << "\n--- Printer Spooler Menu ---\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Print Job\n";
        cout << "3. Display All Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter print job name: ";
            cin >> jobName;
            spooler.addJob(jobName);
            break;
        case 2:
            spooler.processJob();
            break;
        case 3:
            spooler.displayJobs();
            break;
        case 4:
            cout << "Exiting Printer Spooler..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    }

    return 0;
}
