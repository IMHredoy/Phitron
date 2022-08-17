#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int balls[n];
    int min = 100, max = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> balls[i];
        if(balls[i] < min) min = balls[i];
        if(balls[i] > max) max = balls[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        int sumOfMinMax = min+max;
        if(balls[i] == 0) continue;

        sumOfMinMax -= balls[i];
        cout << i + 1 << " ";
        for(int j = i+1; j < n; j++)
        {
            if(balls[j] == sumOfMinMax)
            {
                cout << j + 1 << endl;
                balls[j] = 0;
                break;
            }
        }
    }

    return 0;
}