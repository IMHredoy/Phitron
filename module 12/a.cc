#include <bits/stdc++.h>

using namespace std;

int query(int array[], int i, int j)
{
    int min = array[i];
    ++i;
    while(i <= j)
    {
        if(array[i] < min) min = array[i];
        ++i;
    }
    return min;
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    int t;
    cin >> t;
    getchar();

    int k = 1;
    while(k <= t)
    {
        int n, q;
        cin >> n >> q;
        fastIO();
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        fastIO();
        cout << "Case " << k << ":" << endl;
        for(int i = 0; i < q; i++)
        {
            int I, J;
            cin >> I >> J;
            --I;
            --J;
            cout << query(arr, I, J) << endl;
        }
        ++k;
    }
    return 0;
}