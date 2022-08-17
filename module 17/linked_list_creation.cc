#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(node* &head, int data);
void insertAtTail(node* &head, int data);
void insertAtSpecificPosition(node* &head, int pos, int value);
void display(node* n);
int countLength(node* head);
int searchingByKeyUnique(node* head, int key);
int* searchingByKeyDuplicate(node* head, int key);

void insertAtHead(node* &head, int data)
{
    node* newNode = new node(data);

    newNode->next = head;

    head = newNode;
}

void insertAtTail(node* &head, int data)
{
    node* newNode = new node(data);

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtSpecificPosition(node* &head, int pos, int value)
{
    node* newNode = new node(value);

    node* temp = head;
    int i = 1;
    while(i < pos-1)
    {
        temp = temp->next;
        ++i;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(node* n)
{
    while(n != NULL)
    {
        cout << n->data;
        if(n->next != NULL)
        {
            cout << " --> ";
        }
        n = n->next;
    }
    cout << "\n\n";
}

int countLength(node* head)
{
    int count = 0;
    while(head != NULL)
    {
        ++count;
        head = head->next;
    }
    return count;
}

int searchingByKeyUnique(node* head, int key)
{
    node* temp = head;

    int count = 0;
    while(temp != NULL)
    {
        ++count;
        if(temp->data == key)
        {
            return count;
        }
        temp = temp->next;
    }
    return -1;
}

int* searchingByKeyDuplicate(node* head, int key)
{
    node* temp = head;

    int size = countLength(head);
    int* values = new int[size+1];

    int count = 0, k = 1;
    bool isFound = false;
    while(temp != NULL)
    {
        ++count;
        if(temp->data == key)
        {
            values[k] = count;
            ++k;
            isFound = true;
        }
        temp = temp->next;
    }
    if(isFound)
    {
        values[0] = --k;
        return values;
    }
    else
    {
        values = NULL;
        return values;
    }
}

int main()
{
    node* first = NULL;

    cout << "Press 1 For Insert At Head" << endl;
    cout << "press 2 For Insert at Tail" << endl;
    cout << "Press 3 for insert At Specific Position" << endl;
    cout << "Press 4 For Search Unique List value" << endl;
    cout << "Press 5 For Search Duplicate value" << endl;
    cout << "Press 0 For Exit" << endl;

    int  choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != 0)
    {
        int value, key, pos, x;
        int* values;
        switch (choice)
        {
            case 1:
                cout << "Enter data you want to insert : ";
                cin >> value;
                insertAtHead(first, value);
                break;
            case 2:
                cout << "Enter data you want to insert : ";
                cin >> value;
                insertAtTail(first, value);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter data you want to insert : ";
                cin >> value;
                insertAtSpecificPosition(first, pos, value);
                break;
            case 4:
                cout << "Value you want to search(in unique list): ";
                cin >> key;
                x = searchingByKeyUnique(first, key);
                if(x == -1)
                {
                    cout << key << " not available in list\n";
                }
                else
                {
                    cout << key << " is at " << x << " position\n";
                }
                break;
            case 5:
                cout << "Value you want to search (in duplicate list): ";
                cin >> key;
                values = searchingByKeyDuplicate(first, key);
                if(values == NULL)
                {
                    cout << key << " is not in the list" << endl;
                }
                else
                {
                    cout << key << " is at these positions --> ";
                    for(int i = 1; i <= values[0]; i++)
                    {
                        cout << values[i] << " ";
                    }
                    cout << endl;
                }
            default:
                break;
        }
        cout << "Enter your choice: ";
        cin >> choice;
    }

    display(first);
    
    return 0;
}