/*
PROBLEM STATEMENT: 
Coffee Shop Line (Simple Queue):
Arrival: Customers arrive at the coffee shop and stand in line. 
Order Processing: The first customer in line gets their order taken, 
and the barista starts making the coffee.
Serving: Once the first customer is served, they leave the queue, 
and the next customer in line moves forward to be served.
*/

#include <iostream>
#define SIZE 10
using namespace std;

class CoffeeShop {
private:
    int token_queue[SIZE];
    int front, rear;

public:
    CoffeeShop() {
        front = -1;
        rear = -1;
    }

    int isFull() {
        return rear == SIZE - 1;
    }

    int isEmpty() {
        return (front == -1 || front > rear);
    }

    void enQueue(int t) {
        if (isFull()) {
            cout << "Queue is full! Cannot add token " << t << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        token_queue[rear] = t;
        cout << "Token " << t << " added to queue." << endl;
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Processing order " << token_queue[front] << "..." << endl;
        cout << "Order " << token_queue[front] << " ready!" << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++) {
            cout << token_queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CoffeeShop shop;
    int choice, token = 1;
    char cont = 'y';

    while (cont == 'y') {
        cout << "\n--- Coffee Shop Menu ---\n";
        cout << "1. Get Token\n";
        cout << "2. Process Order\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shop.enQueue(token++);
            break;
        case 2:
            shop.deQueue();
            break;
        case 3:
            shop.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    }

    return 0;
}
