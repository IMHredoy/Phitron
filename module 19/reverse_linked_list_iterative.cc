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

void create(node* &head, int data)
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
void reverse(node* &head)
{
    node* prev = NULL;
    node* current = head;
    if(head == NULL)
    {
        return;
    }
    
    node* next = head->next;
    while(true)
    {
        current->next = prev;
        prev = current;
        current = next;
        if(current == NULL) break;
        next = next->next;
    }
    head = prev;
}
void display(node* head)
{
    while(head != NULL)
    {
        cout << head->data;
        if(head->next != NULL)
        {
            cout << " --> ";
        }
        head = head->next;
    }
    cout << "\n";
}
int main()
{
    node* head = NULL;

    int i = 5;
    while(i--)
    {
        int data;
        cin >> data;
        create(head, data);
    }
    display(head);
    reverse(head);
    display(head);
    return 0;
}