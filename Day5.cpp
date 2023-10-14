#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int histoArea(vector<int>& arr) {
    stack<int> s;
    int area = 0, i = 0, size = arr.size(), t, width;
    while (i < size || !s.empty())
    {
        if (s.empty() || (i < size && arr[i] >= arr[s.top()])) {
            s.push(i);
            i++;
        }
        else
        {
            int top = s.top(); s.pop();
            if (s.empty()) width = i;
            else width=i-s.top()-1;
            t = arr[top] * width;
            if (t > area) area = t;
        }
    }
    return area;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << histoArea(arr);
    return 0;
}
