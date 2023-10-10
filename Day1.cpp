// Hello C++
// Day1 Competetion 3.0
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
    if(head == NULL){head = newnode; return;}
    Node* temp = head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = newnode;
    return;
}

int check(int val, int* arr, int len)
{
    for(int i=0; i<len; i++) { if(arr[i] == val) return 1; }
    return 0;
}
int connected(Node* head, int* arr, int size)
{
    Node* temp = head;
    int var1 = 0;
    int conn = 0;
    bool prevInArr = false;
    
    while (temp != NULL)
    {
        bool flag = check(temp->data, arr, size);
        if (flag)
        {
            if (!prevInArr)
            {
                conn++;
                prevInArr = true;
            }
            var1++;
        }
        else prevInArr = false;
        temp = temp->next;
    }
    return conn;
}
int main()
{
    Node* head = NULL;
    int sizeLL, sizeArr, val;
    cout << "Enter size of Linked List: "; cin >> sizeLL;
    if(sizeLL>=1 && sizeLL<=104)                // Constraints
    {
        cout << "Enter elements in LL: ";
        for(int i=0; i<sizeLL; i++)
        { cin >> val; if(val>=0 && val<sizeLL) insertNode(head, val);}
    }
    cout << "Enter size of array: "; cin >> sizeArr;
    int arr[sizeArr];
    if(sizeArr>=1 && sizeArr<=sizeLL)
    {
        cout << "Enter elements in Array: ";
        for(int i=0; i<sizeArr; i++) 
        { cin >> val; if(val>=0 && val<sizeLL) arr[i] = val;}
    }
    int res = connected(head, arr, sizeArr);
    cout << res;
}