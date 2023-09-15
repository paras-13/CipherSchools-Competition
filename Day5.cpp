// Day 5
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

Node* insertNode(Node* &head, int val)
{
    Node* temp = head;
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return head;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
}

Node* createLinkedList(Node* &head)
{
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    cout << "Enter elements: ";
    int val;
    while (n--)
    {
        cin >> val;
        insertNode(head, val);
    }
    return head;
}

void mergeAndSort(Node* &main_head, Node* new_head)
{
    if (main_head == NULL) {
        main_head = new_head;
        return;
    }
    
    Node* temp1 = main_head;
    Node* temp2 = new_head;
    Node* merged = NULL;
    Node* tail = NULL;
    
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data){
            if (merged == NULL){
                merged = temp1; tail = temp1;
            } 
            else{
                tail->next = temp1; tail = temp1;
            }
            temp1 = temp1->next;
        }

        else{
            if (merged == NULL){
                merged = temp2; tail = temp2;
            } 
            else{
                tail->next = temp2; tail = temp2;
            }
            temp2 = temp2->next;
        }
    }
    
    if (temp1 != NULL) tail->next = temp1;
    if (temp2 != NULL) tail->next = temp2;
    main_head = merged;
}

void print(Node* temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* main_head = NULL;
    int size;

    cout << "Number of linked lists: ";
    cin >> size;
    Node* arr[size];
    for (int i = 0; i < size; i++)
    {
        Node* head = NULL;
        cout << endl << "Linked list " << i + 1 << endl;
        arr[i] = createLinkedList(head);
    }
    for(int j=0; j<size; j++)
    mergeAndSort(main_head, arr[j]);
    print(main_head);
    return 0;
}