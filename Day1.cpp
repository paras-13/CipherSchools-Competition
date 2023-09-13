// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
void insertNode(Node* &head, int val, Node* &tail)
{
    Node* newnode = new Node(val);
    newnode->next = head;
    newnode->prev = NULL;
    
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
    
    Node *temp = head;
    while(temp->next != NULL)
    temp=temp->next;
    tail = temp;
}
int sumTwin(Node* &head, Node* &tail, int n)
{
    n=n/2;
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(head->data+tail->data > max) max = head->data+tail->data;
        head = head->next;
        tail=tail->prev;
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    int val;
    Node *head = NULL;
    Node* tail = NULL;
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(head, val, tail);
    }
    cout <<sumTwin(head, tail, n);
    return 0;
}
