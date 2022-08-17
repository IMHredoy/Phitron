#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int good = 0;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            sum = sum | arr[i];
            if(sum >= k) ++good;
            int j = i;
            sum = 0;
            while(j--)
            {
                sum = sum | arr[j];
            }
        }
        cout << good << endl;
    }

    return 0;
}