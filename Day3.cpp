// Day 3
#include <iostream>
#include <deque>
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

void insertNode(Node* &head,int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if(head==NULL) {head = newnode; return;}
    Node* temp = head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = newnode;
}
Node* middleNode(Node* head)
{
    Node* ptr1 = head; Node* ptr2 = head;
    while (ptr1 != nullptr && ptr1->next != nullptr) {
        ptr2 = ptr2->next; ptr1 = ptr1->next->next;
    }
    return ptr2;
}
void reorderList(Node* head) {
    if (head == NULL || head->next == NULL) return;
    Node* prev = NULL;
    Node* temp = middleNode(head);
    Node* next;
    while (temp != NULL) 
    {
        next = temp->next; temp->next = prev;
        prev = temp; temp = next;
    }
    Node* front = head; Node* back = prev;
    while (back->next != NULL)
    {
        next = front->next;
        front->next = back;
        front = next;
        next = back->next;
        back->next = front;
        back = next;
    }
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main()
{
    Node* head = NULL;
    int sizeLL, val;
    cout << "Enter size of Linked List: ";
    cin >> sizeLL;
    cout << "Enter elements: ";
    for(int i=0; i<sizeLL; i++)
    {
        cin >> val;
        insertNode(head, val);
    }
    reorderList(head);
    cout << "Reordered list:  ";
    printLL(head);
}