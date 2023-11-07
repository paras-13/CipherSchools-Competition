// Day2 Problem-2
#include <bits/stdc++.h>
using namespace std;

int HistoArea(int* arr, int n) {
        int prev, next;
        int area=0;
        for(int i=0;i<n;i++)
        {
            int count=1; prev=i-1; next=i+1;
            while(prev>=0 && arr[i]<=arr[prev]) 
            { 
                count++;
                prev--;
            }
            while(next<n && arr[i]<=arr[next])
            {
                count++;
                next++;
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