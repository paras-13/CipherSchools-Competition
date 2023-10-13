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

void reorderList(Node* head)
{
    if (head == NULL || head->next == NULL) return;

    Node* temp = head;
    Node* t_head = head;
    deque<Node*> dq;

    while (temp != NULL)
    {
        dq.push_back(temp);
        temp = temp->next;
    }

    while (!dq.empty())
    {
        t_head->next = dq.front();
        t_head = dq.front();
        dq.pop_front();
        if (!dq.empty()) {
            t_head->next = dq.back();
            t_head = dq.back();
            dq.pop_back();
        }
    }
    t_head->next = NULL;
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