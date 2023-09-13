// Day 2 Problem
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void evenInsert(Node* &head2, int val)
{
    Node* temp = head2;
    Node* newnode = new Node(val);

    newnode->next = NULL;
    if(head2 == NULL) {head2 = newnode; return;}

    while(temp->next != NULL) temp=temp->next;
    temp->next = newnode;
    return;
}
void oddInsert(Node* &head1, Node* &tail, int val)
{
    Node* temp = head1;
    Node *newnode = new Node(val);
    newnode->next = NULL;

    if(head1 == NULL) {head1 = newnode; return;}
    while(temp->next != NULL) 
    temp = temp->next;
    temp->next = newnode;

    Node* last = head1;
    while(last->next!=NULL)
    last=last->next;
    tail = last;
    return;
}
void print(Node* head1)
{
    Node *temp = head1;
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int val;
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* tail = NULL;
    cout << "Enter elements: ";
    for(int i=1; i<=n; i++)
    {
        cin >> val;
        if(i%2==0) evenInsert(head2, val);
        else oddInsert(head1, tail, val);
    }
    tail->next = head2;
    print(head1);
}