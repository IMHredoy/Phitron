#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    string s;
    double d;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    node(string data)
    {
        this->s = data;
        this->next = NULL;
    }
    node(double d)
    {
        this->d = d;
        this->next = NULL;
    }
};

void createNode(node* &address, int item)
{
    node* newNode = new node(item);
    if(address == NULL)
    {
        address = newNode;
    }
    else
    {
        address->next = newNode;
    }
}
void createNode(node* &address, string item)
{
    node* newNode = new node(item);
    if(address == NULL)
    {
        address = newNode;
    }
    else
    {
        address->next = newNode;
    }
}
void createNode(node* &address, double item)
{
    node* newNode = new node(item);
    if(address == NULL)
    {
        address = newNode;
    }
    else
    {
        address->next = newNode;
    }
}

void printNode(node* head)
{
    while(head != NULL)
    {
        cout << head->data;
        if(head->next != NULL)
            cout << " --> ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    node* head = NULL;
    
    int n;
    cin >> n;
    cout << "What type of Data do you want to insert in list ? Press according to your type :" << endl;
    while(n--)
    {
        int n;
        string s;
        double d;
        cout << "string - s, int - i, double - d --> ";
        char choiceOfData;
        cin >> choiceOfData;
        // cout << "Where Do you want to insert ? At the head or At the tail press h or t --> ";
        // char choiceOfPlace;
        // cin >> choiceOfPlace;

        cout << "Enter List Item: ";
        if(choiceOfData == 's')
        {
            cin >> s;
            createNode(head, s);
        }
        else if(choiceOfData == 'i')
        {
            cin >> n;
            createNode(head, n);
        }
        else if(choiceOfData == 'd')
        {
            cin >> d;
            createNode(head, d);
        }

    }

    printNode(head);

    return 0;
}