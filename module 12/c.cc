#include <bits/stdc++.h>

using namespace std;

void sort(int array[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while(array[j] > key && j >= 0)
        {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n], sum[n];
        cin >> arr[0];
        sum[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, n);
        int min = arr[0], deletedElements = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > min)
            {
                deletedElements++;
            }
        }
        cout << deletedElements << endl;
    }
    return 0;
}