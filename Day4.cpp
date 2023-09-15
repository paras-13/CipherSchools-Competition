#include<iostream>
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

void insertNode(Node* &head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void reverseNode(Node* &head, Node* &t, int ch, Node* &main, Node* &tail, Node* &temp)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (ch)
    {
        tail->next = temp;
        tail = head;
        head = t;
        temp = head;
    }
    else
    {
        tail = head;
        head = t;
        temp = head;
        main = prev;
    }
}

void traverseNode(Node* &head, int key, int n)
{
    int ch = 0;
    Node* temp = head;
    Node* tail = NULL;
    Node* main = NULL;
    Node* t = NULL;
    int count = 0;
    while (temp!= NULL)
    {
        count++;
        if (count == key)
        {
            t = temp->next;
            temp->next = NULL;
            reverseNode(head, t, ch , main, tail, temp);
            ch++;
            count = 0;
        }
        else temp = temp->next;
    }
    if(count !=0 && count < key ) tail->next = head;
    // if (n%2 == 0) tail->next = NULL;
    head = main;
}


void print(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    int n, val;
    cout << "Enter number of elements to enter: "; cin >> n;
    int loose = n;
    cout << "Enter elements: ";
    while (loose--)
    {
        cin >> val;
        insertNode(head, val);
    }
    cout << "Enter key: ";
    int key; cin >> key;
    if(key <= n)
    {
    traverseNode(head, key, n); print(head);
    }
    else print(head);
    return 0;
}
