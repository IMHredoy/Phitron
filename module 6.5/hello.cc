#include <iostream>
#include <string>

using namespace std;

class YouTubeChanel
{
private:
    string name;
    string ownerName;
    int subscribersCount = 0;

public:
    YouTubeChanel(string n, string oN, int sc)
    {
        name = n;
        ownerName = oN;
        subscribersCount = sc;
    }
    void subUnsub(char c)
    {
        if (c == 's')
            ++subscribersCount;
        else
            --subscribersCount;
    }
    void getData()
    {
        cout << "Chanel Name " << name << endl;
        cout << "Owner Name " << ownerName << endl;
        cout << "Total Subscriber " << subscribersCount << endl;
    }
};

int main()

{
    YouTubeChanel user1234("Coding For Geeks", "Iftekhar Mahmud", 0);
    while (true)
    {
        char ch;
        cout << "For Subscribe press 's' " << endl;
        cout << "For Unsubscribe press 'u' " << endl;
        cin >> ch;
        if (ch == 't')
            break;
        else
            user1234.subUnsub(ch);
    }
    user1234.getData();
    return 0;
}