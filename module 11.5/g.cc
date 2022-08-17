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

        int players[n];
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> players[i];
            if(players[i] > k)
            {
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}