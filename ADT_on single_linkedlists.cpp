
/* ADT on Linked List */

#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

// Self-referential structure
struct Node {
public:
    int val;
    Node* next;
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to insert a node after a specified value
void insertAfter(Node* head, int targetVal, int newVal) {
    Node* current = head;
    while (current != nullptr && current->val != targetVal) {
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "Value " << targetVal << " not found in the list." << endl;
        return;
    }
    
    Node* newNode = new Node();
    newNode->val = newVal;
    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a node before a specified value
void insertBefore(Node*& head, int targetVal, int newVal) {
    // Case when the list is empty
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    // Case when inserting before the head
    if (head->val == targetVal) {
        Node* newNode = new Node();
        newNode->val = newVal;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->val != targetVal) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Value " << targetVal << " not found in the list." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->val = newVal;
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node 
void deleteNode(Node*& head, int targetVal) {
    // If the list is empty
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    // If the node to be deleted is the head node
    if (head->val == targetVal) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // Search for the node to be deleted
    Node* current = head;
    while (current->next != nullptr && current->next->val != targetVal) {
        current = current->next;
    }
    // If the node to be deleted was not found
    if (current->next == nullptr) {
        cout << "Value " << targetVal << " not found in the list." << endl;
        return;
    }
    // Delete the node
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Function to update a node
void updateNode(Node* & head, int numUpdate, int newVal) {
        Node* current = head;
    while(current->val != numUpdate){
        current = current->next;
    }
    current->val = newVal;
}


int main() {
    // Declaring nodes
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    // Assigning Values to the node and Linking them
    node1->val = 10;
    node1->next = node2;
    node2->val = 20;
    node2->next = node3;
    node3->val = 30;
    node3->next = node4;
    node4->val = 40;
    node4->next = nullptr;
    // Printing the linked list
    printList(node1);

char op[10];
cout<<"Enter the operation you want to perform: ";
cin>>op;

if(strcmp(op, "insertion") == 0) {
    char a_or_b;
    int targetVal, newVal;

    cout << "\n(a/b): ";
    cin >> a_or_b;

    if (a_or_b == 'a') {
        cout << "After which number: ";
        cin >> targetVal;
        cout << "Insert value: ";
        cin >> newVal;
        insertAfter(node1, targetVal, newVal);
    } else if (a_or_b == 'b') {
        cout << "Before which number: ";
        cin >> targetVal;
        cout << "Insert value: ";
        cin >> newVal;
        insertBefore(node1, targetVal, newVal);
    } else {
        cout << "Invalid option." << endl;
    }

    // Printing the new list after insertion operation
    printList(node1);

    // Cleanup: delete nodes to avoid memory leaks
    Node* current = node1;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

if(strcmp(op, "deletion") == 0) {
    int delNum;
    cout<<"Enter the number you want to delete: ";
    cin>>delNum;
    deleteNode(node1, delNum);
    printList(node1);
}

if(strcmp(op, "update") == 0) {
    int numUpdate, newVal;
    cout<<"Enter the Number you want to Update: ";
    cin>>numUpdate;
    cout<<"Enter the New Value of the Number: ";
    cin>>newVal;
    updateNode(node1, numUpdate, newVal);
    printList(node1);
}
    

    return 0;
}
