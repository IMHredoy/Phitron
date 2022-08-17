#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int score[2][n];
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                score[i][j] = 0;
            }
        }
        int temp;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            score[0][i] += (temp*20);
        }
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            score[1][i] += (temp*10);
        }
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            temp = score[0][i] - score[1][i];
            if(temp > max) max = temp;
        }
        cout << max << endl;
    }
    
    return 0;
}