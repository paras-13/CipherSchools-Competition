#include <iostream>
#include <vector>
using namespace std;

int binary(vector<int> b, int ele)
{
    int beg = 0;
    int end = b.size() - 1;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (b[mid] == ele) return mid;
        else if (b[mid] < ele) beg = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int lower(vector<int>& temp_v, int ele) {
    int beg = 0;
    int end = temp_v.size();
    while (beg < end) {
        int mid = beg + (end - beg) / 2;
        if (temp_v[mid] < ele) beg = mid + 1;
        else end = mid;
    }
    return beg;
}
int find(vector<int>& a, vector<int>& b)
{
    int sizeA = a.size(); 
    int sizeB = b.size(), sizeC;
    vector<int> temp;
    for (int i = 0; i < sizeA; i++) {
        if (binary(b, a[i])!=-1)
        {
            int var = lower(temp, a[i]);
            if (var == temp.size()) temp.push_back(a[i]);
            else temp[var] = a[i];
        }
    }
    sizeC = 2*temp.size();
    return sizeA+sizeB - sizeC;
}

int main() {
    int n, m;
    cout << "Enter size of arr1: "; cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr1[i];
    cout << "Enter size of arr2: "; cin >> m;
    vector<int> arr2(m);
    cout << "Enter elements: ";
    for (int i = 0; i < m; i++) cin >> arr2[i];
    cout << find(arr1, arr2);
}
