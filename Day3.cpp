#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void append(Node *&head, int data, int n)
{

    Node *temp1 = new Node(data);
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
    }
    Node *temp2 = head;
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Sort(Node *&head, int size)
{
    Node *temp;
    int i, j, flag;

    for (i = 0; i < size - 1; i++)
    {

        temp = head;
        flag = 0;

        for (j = 0; j < size - i - 1; j++)
        {

            Node *p1 = temp;
            Node *p2 = p1->next;

            if (p1->data > p2->data)
            {
                swap(p1, p2);
                flag = 1;
            }

            temp = temp->next;
        }
        if (flag == 0)
            break;
    }
}

void printnodelist(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in linked list";
    cin >> n;
    int arr[n];

    Node *head = NULL;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        append(head, arr[i], n);
    }

    cout << "--" << head->next->data << endl;
    cout << "before adding of newnode : " << endl;
    printnodelist(head);
    Sort(head, n);
    cout << "after adding of newnode : " << endl;
    printnodelist(head);
    return 0;
}
