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

int main()
{
    node* first = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int count = countLength(first);
    cout << "Length of linked list is : " << count << "\n";

    return 0;
}