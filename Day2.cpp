// Day2 - Problem
#include<iostream>
using namespace std;
int findsum(int* arr, int n)
{
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        for(int k=n-1; k>i+1; k--)
        {
            for(int j=i+1; j<k; j++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(flag) return 1;
    else return 0;
}
int main()
{
    int n;
    cout <<"Enter the number of elements in array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    cout << findsum(arr, n);
    
}