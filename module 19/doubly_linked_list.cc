#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node* prev;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(node* &head, int value)
{
    node* newNode = new node(value);

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(node* &head, int value)
{
    node* newNode = new node(value);

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
        newNode->prev = temp;
    }
}

int main()
{

}