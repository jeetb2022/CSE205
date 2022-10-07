#include<iostream>
#include<algorithm>
using namespace std;

int search(int arr[], int lo, int hi, int x)
{
    int mid;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            hi = mid-1;
        else    
            lo = mid+1;
    }
    return lo;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        /* code */
        int x = search(arr, 0, i-1, arr[i]);
        cout<<x<<endl;
        // swap(arr[x], arr[i]);
        int j = i;
        while(j >= x+1)
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    
}
int main(){

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
}
