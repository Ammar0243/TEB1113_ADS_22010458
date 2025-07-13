#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* head; // front
    Node* tail; // rear

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(string name) {
        Node* node = new Node(name);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr; // Queue became empty
        }
    }

    void displayQueue() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->name;
            if (curr->next != nullptr) cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Ahmed");
    q.enqueue("Alice");

    cout << "Queue after enqueuing 3 items: ";
    q.displayQueue();

    q.dequeue();

    cout << "Queue after 1 dequeue: ";
    q.displayQueue();

    return 0;
}
