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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addItem(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void displayList() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    void deleteValue(string name) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->name == name) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                if (curr == tail) {
                    tail = prev;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    LinkedList std_list;

    std_list.addItem(node1);
    std_list.addItem(node2);
    std_list.addItem(node3);

    cout << "List before deletion: ";
    std_list.displayList();

    std_list.deleteValue("Ahmed");

    cout << "List after deletion: ";
    std_list.displayList();

    return 0;
}