#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int *arr;      
    int *top;
    int *next;     
    int max_size, Nstack, free;  

public:
    Stack(int n, int s)
    {
        max_size = n;
        Nstack = s;
        arr = new int[max_size];
        top = new int[Nstack];
        next = new int[max_size];

        for (int i = 0; i < Nstack; i++) top[i] = -1;
        free = 0;
        for (int i = 0; i < max_size - 1; i++)
            next[i] = i + 1;
        next[max_size - 1] = -1;
    }
    bool push(int stackNum, int value);
    int pop(int stackNum);
};

bool Stack::push(int stackNum, int value) {
    if (free == -1) return false;
    int temp = free;
    free = next[temp];
    next[temp] = top[stackNum];
    top[stackNum] = temp;
    arr[temp] = value;
    return true;
}

int Stack::pop(int stackNum)
{
    if (top[stackNum] == -1) return -1;
    int temp = top[stackNum];
    top[stackNum] = next[temp];
    next[temp] = free;
    free =temp;
    return arr[temp];
}

int main()
{
    int n, s, q;
    int choice, stackNum, element;
    cin >> n >> s >> q;
    Stack mystack(n, s);
    cout << "Enter query: \n";
    while (q--)
    {
        cin >> choice;
        if (choice == 1)
        {
            cin >> element >> stackNum;
            if (mystack.push(stackNum, element))
                cout << "True\n\n";
            else
                cout << "False\n\n";
        }
        else if (choice == 2)
        {
            cin >> stackNum;
            cout << mystack.pop(stackNum) << endl << endl;
        }
        else
            cout << "Invalid choice\n";
    }
    return 0;
}
