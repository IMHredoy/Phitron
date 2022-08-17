#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0)
            {
                if(j <= n / 2 || j == n-1)
                {
                    
                    cout << A[i][j] << " ";
                    sum += A[i][j];
                }
                else
                {
                    cout << " ";
                }
            }
            else if(i == n - 1)
            {
                if(j == 0 || j >= n / 2)
                {
                    cout << A[i][j] << " ";
                    sum += A[i][j];
                }
                else
                {
                    cout << " ";
                }
            }
            else if(i < n / 2)
            {
                if(j == n / 2 || j == n - 1)
                {
                    cout << A[i][j] << " ";
                    sum += A[i][j];
                }
                else
                {
                    cout << " ";
                }
            }
            else if(i > n / 2)
            {
                if(j == 0 || j == n / 2)
                {
                    cout << A[i][j] << " ";
                    sum += A[i][j];
                }
                else
                {
                    cout << " ";
                }
            }
            else if(i == n / 2)
            {
                cout << A[i][j] << " ";
                sum += A[i][j];
            }
        }
        cout << endl;
    }
    cout << sum << endl;
    return 0;
}