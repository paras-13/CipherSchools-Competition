// Day2 Problem1
#include <iostream>
using namespace std;
class Stack
{
    private:
    int MAX_SIZE;
    int *arr;
    int top = -1;

    public:
    void setSize(int x)
    {
        MAX_SIZE = x;
        arr = new int[MAX_SIZE];
    }

    bool push(int x);
    int pop();
};

bool Stack :: push(int element)
{
    if(top == MAX_SIZE-1) return false;
    else
    {
        top++;
        arr[top] = element;
        return true;
    }
}

int Stack :: pop()
{
    int temp;
    if(top == -1) return -1;
    else
    {
        temp = arr[top];
        top--;
        return temp;
    }
}

int main()
{
    int n, s, q;
    int choice, ele, stack;
    cout << "Number of stacks: "; cin >> n;
    cout << "Size of array: "; cin >> s;
    cout << "Number of queries: "; cin >> q;
    Stack mystack[n];
    for(int i=0; i<n; i++) mystack[i].setSize(s);
    while(q--)
    {   cout << "\nEnter query: ";
        cin >> choice;
        if(choice == 1)
        {
            cin >> ele >> stack;
            if(mystack[stack-1].push(ele)) cout << "True\n";
            else cout << "False\n";
        }
        else if (choice == 2)
        {
            cin >> stack;
            cout << mystack[stack-1].pop() << endl;
        }
        else cout << "Invalid choice\n";
    }

}