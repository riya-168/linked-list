#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node *Next;
    Node(int val) {
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int searchByValueUnique(Node *&head, int key);

void insertAtTail(Node *&head, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void display(Node *n) {
    while (n != NULL) {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl << endl;
}

int searchByValueUnique(Node *&head, int key) {
    Node *temp = head;
    int count = 1;
    if (temp == NULL) {
        return -1;
    }
    while (temp->value != key) {
        if (temp->Next == NULL) {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

int main() {
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Search a value (unique list)" << endl
         << "Choice 0: EXIT" << endl << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice != 0) {
        switch (choice) {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the value you want to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl << "Final Linked List: ";
    display(head);
    if (position != -1) {
                cout << "The number: " << value << " is at position " << position << endl;
            } else {
                cout << "The number is not yet in the list" << endl;
                   }
    return 0;
}
