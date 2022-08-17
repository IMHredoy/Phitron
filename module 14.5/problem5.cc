#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int matrix[m][n];
    int count[11] = {0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            ++count[matrix[i][j]];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(count[matrix[i][j]] > 1)
            {
                --count[matrix[i][j]];
                matrix[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}