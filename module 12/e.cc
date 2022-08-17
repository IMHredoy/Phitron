#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    long long int k = 1;
    while(k <= t)
    {
        long long int n, q;
        cin >> n >> q;
        long long int sacks[n], sum[n];
        cin >> sacks[0];
        sum[0] = sacks[0];
        for(long long int i = 1; i < n; i++)
        {
            cin >> sacks[i];
            sum[i] = sum[i-1] + sacks[i];
        }

        cout << "Case " << k << ":" << endl;
        for(long long int i = 0; i < q; i++)
        {
            long long int charity, deposit;
            long long int qCode;
            cin >> qCode;
            if(qCode == 1)
            {
                cin >> charity;
                cout << sacks[charity]<<endl;
                int temp = sacks[charity];
                while(charity < n)
                {
                    sum[charity] -= temp;
                    ++charity;
                }
                sacks[charity] = 0;
            }
            else if(qCode == 2)
            {
                int position;
                cin >> position >> deposit;
                sacks[position] += deposit;
                while(position < n)
                {
                    sum[position] += deposit;
                    ++position;
                }
            }
            else if(qCode == 3)
            {
                int i, j;
                cin >> i >> j;
                if(i == 0)
                {
                    cout << sum[j] << endl;
                }
                else
                {
                    i--;
                    cout << sum[j]-sum[i] << endl;
                }
            }
        }
        k++;
    }
    return 0;
}