//Insertion at specific position 
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void insertAtSpecificPosition(Node *&head,int pos,int val);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl << endl;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }
    return count;
}
void insertAtSpecificPosition(Node *&head,int pos,int val){
    int i =0;
    Node *temp = head;
    while(i<pos-2)
    {
        temp=temp->Next;
        i++;
    }
    Node *newNode= new Node(val);
    newNode->Next=temp->Next;
    temp->Next=newNode;
}

int main()
{
    Node *head = NULL;
    int value,position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insert at Specific Position" << endl
         << "Choice 0: EXIT" << endl
         << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice != 0)
    {
       // cout << "Enter the value: ";
        //cin >> value;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>> value;
            insertAtTail(head, value);
            break;
   case 3:
            cout << "Enter your desired position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            cout << "List before insertion at position " << position << ": ";
            display(head);
            insertAtSpecificPosition(head, position, value);
            cout << "List after insertion at position " << position << ": ";
            display(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    cout << endl << "Final Linked List: ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}