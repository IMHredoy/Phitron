#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int freq[1001] = {0};
        int arr[n], MAX = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] > MAX) MAX = arr[i];
            ++freq[arr[i]];
        }
        int sum = 0, max = 0;
        for(int i = 0; i <= MAX; i++)
        {   
            sum += freq[i];
            if(freq[i] > max) max = freq[i];
        }
        cout << sum - max << endl;
    }
    return 0;
}