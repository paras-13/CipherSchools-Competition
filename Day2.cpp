// Day 2;

#include <iostream>
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

void insertNode(Node* &head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if(head == NULL) {head = newnode; return;}
    Node* temp = head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = newnode;
}

void evenSort(Node* &head)
{
    Node* temp = head;
    Node* evenH = NULL;
    Node* evenT = NULL;
    Node* oddH = NULL;
    Node* oddT = NULL;

    if (temp == NULL) return;
    while (temp != NULL){
        if (temp->data % 2 == 0)
        {
            if (evenH == NULL) { evenH = temp; evenT = temp;}
            else{evenT->next = temp; evenT = temp;}
        }
        else
        {
            if (oddH == NULL) { oddH = temp; oddT = temp; }
            else { oddT->next = temp; oddT = temp; }
        }
        temp = temp->next;
    }

    if (evenT != NULL) evenT->next = oddH;
    if (oddT != NULL) oddT->next = NULL;
    if(evenT == NULL) evenH = oddH;
    head = evenH;
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
    cout << "Enter size of linked List: "; cin >> sizeLL;
    cout << "Enter elements: ";
    for(int i=0; i<sizeLL; i++)
    {
        cin >> val;
        insertNode(head, val);
    }
    evenSort(head);
    printLL(head);
}
