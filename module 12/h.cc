#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int starting = s.find('A');
    int ending = s.find_last_of('Z');
    cout << abs(starting - ending) + 1 << "\n";
    return 0;
}