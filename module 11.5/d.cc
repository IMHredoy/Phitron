#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int motherFuckerSnakes[n];
        for(int i = 0; i < n; i++)
        {
            cin >> motherFuckerSnakes[i];
        }
        
        for(int i = 0; i < q; i++)
        {
            int temp, count = 0;
            cin >> temp;
            for(int j = 0; j < n; j++)
            {
                if(motherFuckerSnakes[j] >= temp)
                {
                    count++;
                }
                else
                {
                    int needToEat = temp - motherFuckerSnakes[j];
                    int x = motherFuckerSnakes[j];
                    if(j+needToEat < n)
                    {
                        int k = j + 1;
                        while(k < n)
                        {
                            if(motherFuckerSnakes[k] >= temp)
                            {
                                ++count;
                                ++k;
                            }
                            else
                            {
                                ++x;
                                if(x >= temp)
                                {
                                    ++k;
                                    ++count;
                                    break;
                                }
                            }
                        }
                        j = --k;
                    }
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}
