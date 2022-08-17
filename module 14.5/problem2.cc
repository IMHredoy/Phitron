#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int matrix[n][n];
    int major[n], minor[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if(i == j)
            {
                major[i] = matrix[i][j];
            }
            if(j == n - (i + 1))
            {
                minor[i] = matrix[i][j];
            }
        }
    }
    cout << "Major diagonal: ";
    for(int i = 0; i < n; i++)
    {
        cout << major[i] << " ";
    }
    cout << "\n";
    cout << "Minor diagonal: ";
    for(int i = 0; i < n; i++)
    {
        cout << minor[i] << " ";
    }
    cout << "\n";
    return 0;
}