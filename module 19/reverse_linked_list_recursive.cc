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
node* reverse(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        if(head == NULL)
        {
            cout << "The list is empty" << endl;
        }
        return head;
    }
    node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
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

    int i = 1;
    while(i--)
    {
        int data;
        cin >> data;
        create(head, data);
    }
    display(head);
    reverse(head);
    cout << head->next << endl;
    return 0;
}