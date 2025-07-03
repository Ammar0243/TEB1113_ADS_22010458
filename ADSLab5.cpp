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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push: insert at the top
    void push(Node* node) {
        node->next = top;
        top = node;
    }

    // Pop: remove from the top
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Display the stack
    void displayStack() {
        Node* currNode = top;
        while (currNode != nullptr) {
            cout << currNode->name;
            if (currNode->next != nullptr) {
                cout << " -> ";
            }
            currNode = currNode->next;
        }
        cout << endl;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    Stack std_stack;

    std_stack.push(node1);
    std_stack.push(node2);
    std_stack.push(node3);

    cout << "Stack: ";
    std_stack.displayStack(); // Alice -> Ahmed -> Ali

    std_stack.pop();
    cout << "After pop: ";
    std_stack.displayStack(); // Ahmed -> Ali

    return 0;
}
