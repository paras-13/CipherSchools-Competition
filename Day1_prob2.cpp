#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

void insertNode(Node*& head, int val) {
    Node* newnode = new Node(val);
    if (!head) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

Node* partition(Node* head, Node* tail) {
    Node* pivot = head;
    Node* curr = head->next;
    Node* prev = head;

    while (curr != tail->next) {
        if (pivot->data > curr->data) {
            swap(prev->next->data, curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(prev->data, pivot->data);
    return prev;
}

void quickSort(Node*& headRef, Node* tail) {
    Node* head = headRef;
    if (!head || !head->next || head == tail)
        return;
    Node* pi = partition(head, tail);
    quickSort(headRef, pi);
    quickSort(pi->next, tail);
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int t;
    cout << "Enter total test cases: ";
    cin >> t;
    while (t--) {
        Node* head = NULL;
        int n, val;
        cout << "Enter number of elements in LL: ";
        cin >> n;
        cout << "LL -->: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            insertNode(head, val);
        }
        Node* tail = head;
        while (tail->next)
            tail = tail->next;
        quickSort(head, tail);
        cout << "SORTED --> ";print(head);cout << endl;
        head = NULL;
        cout << endl;
    }
}