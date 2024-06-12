//creation of linked-list
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next; //node type pointer
    //constructer creation
    Node (int val)
    {
        value = val;
        Next = NULL;
    }
};
void insertAtTail(Node* &head, int val)
{
    Node *newNode = new Node(val);
    if(head ==NULL)
    {
        head =newNode;
        return;
    }
    //   head != NULL but Next == NULL
    Node *temp = head ;
    while(temp->Next !=NULL)
    {
        temp = temp -> Next;
    }
    temp ->Next =newNode;


}

void display(Node *n)
{
    while(n!= NULL)
    {
        cout<< n->value;
        if(n->Next != NULL)
            cout<<" ->";
        n=n->Next;
    }
    cout<<endl<<endl; 
}
int main()
{
    Node *head = NULL;
    int n;
    char choice = 'Y';
    while (choice =='Y')
    {
        cout<<"Enter the value: ";
        cin>>n;
        insertAtTail(head, n);
        cout<<"Do you want to continue:(Y/N) ";
        // hello
        cin>>choice;
    }   
    display(head);
    return 0;

}