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

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert node at the end (enqueue style)
    void addItem(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            tail->next = head; // circular connection
        } else {
            tail->next = node;
            tail = node;
            tail->next = head; // maintain circularity
        }
    }

    // Display the circular linked list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* currNode = head;
        do {
            cout << currNode->name;
            currNode = currNode->next;
            if (currNode != head) cout << " -> ";
        } while (currNode != head);
        cout << " -> (back to head: " << head->name << ")" << endl;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    CircularLinkedList std_list;

    std_list.addItem(node1);
    std_list.addItem(node2);
    std_list.addItem(node3);

    cout << "Circular List: ";
    std_list.displayList();

    return 0;
}
