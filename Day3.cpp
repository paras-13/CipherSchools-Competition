// Day 3
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x; next = NULL; prev = NULL;
    }
};
void insertNode(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = NULL;
    Node *temp = head;
    if (head == NULL)
    {
        head = newnode; return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode; return;
}
void rotateNode(Node* &head)
{
    Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    Node* t = temp;

    temp = temp->next;
    temp->prev = t;
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while(temp !=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    int n, val;
    Node *head = NULL;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";

    while (n--)
    {
        cin >> val;
        insertNode(head, val);
    }
    int key;
    cout << "Enter key: "; cin >> key;
    for(int i=0; i<key; i++)
    rotateNode(head);
    print(head);
}