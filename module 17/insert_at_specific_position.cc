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
int main()
{
    node* first = NULL;

    cout << "Press 1 For Insert At Head | press 2 For Insert at Tail | Press 0 For Exit" << endl;
    cout << "First choice will be default at Head\n";
    int choice = 1;
    while (choice == 1 || choice == 2)
    {
        int value;
        cout << "Enter data you want to insert : ";
        cin >> value;
        switch (choice)
        {
            case 1:
                insertAtHead(first, value);
                break;
            case 2:
                insertAtTail(first, value);
                break;
            default:
                break;
        }
        cout << "Enter your choice: ";
        cin >> choice;
    }

    display(first);
    
    return 0;
}