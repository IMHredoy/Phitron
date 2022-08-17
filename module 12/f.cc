#include <bits/stdc++.h>

using namespace std;

int main()
{
    int freq[101] = {0};
    int a, b, c;
    cin >> a >> b >> c;
    ++freq[a];
    ++freq[b];
    ++freq[c];
    int ans = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(freq[i] > 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}