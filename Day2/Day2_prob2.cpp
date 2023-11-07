// Day2 Problem-2
#include <bits/stdc++.h>
using namespace std;

int HistoArea(int* arr, int n) {
        int left, right, area=0;
        for(int i=0;i<n;i++)
        {
            int count=1; left=i-1; right=i+1;
            while(left>=0 && arr[i]<=arr[left]) { 
                count++; left--;
            }
            while(right<n && arr[i]<=arr[right]) {
                count++; right++;
            }
            int t_area=arr[i]*count;
            area=max(area, t_area);
            int temp=arr[i];
            while(i<n && arr[i]==temp) i++;          
            i--;
        }
        return area;
    }
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        cout << HistoArea(arr, n) << endl;
    }
}