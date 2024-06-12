//creation of linked-list
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next; //node type poointer
};

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
    Node *head =new Node();
    Node  *second=new Node();
    Node *third=new Node();
    Node *fourth =new Node();
    Node *fifth =new Node();
    
    head ->value =3;
    second ->value =5;
    third ->value =7;
    fourth->value =2;
    fifth->value =1;

    head->Next=second;
    second->Next=third;
    third->Next=fourth;
    fourth->Next=fifth;
    fifth->Next=NULL;

    display(head);
    return 0;

}