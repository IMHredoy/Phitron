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
void insertAtRandomPosition(node* &head, int pos, int data)
{
    node* newNode = new node(data);
    node* temp = head;

    int count = 1;
    while(count < pos-1)
    {
        if(temp != NULL)
        {
            ++count;
            temp = temp->next;
        }
        else
        {
            cout << "You entered Wrong Position" << endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int findLength(node* head)
{
    int count = 0;
    while(head != NULL)
    {
        ++count;
        head = head->next;
    }
    return count;
}

int searchElement(node* head, int key)
{
    int pos = 0;
    while(head != NULL)
    {
        ++pos;
        if(head->data == key)
        {
            return pos;
        }
        head = head->next;
    }
    return -1;
}
int* searchElementDuplicate(node* head, int key)
{
    int pos = 0;
    int size = findLength(head);
    int* positions = new int[size+1];
    int k = 1;
    bool isFound = false;
    while(head != NULL)
    {
        ++pos;
        if(head->data == key)
        {
            isFound = true;
            positions[k] = pos;
            ++k;
        }
        head = head->next;
    }
    if(isFound)
    {
        positions[0] = --k;
        return positions;
    }
    else
    {
        positions = NULL;
        return positions;
    }
}
void insertAfterSpecificValue(node* &head, int newData, int theSpecificValue)
{
    int pos = searchElement(head, theSpecificValue);
    insertAtRandomPosition(head, pos+1, newData);
}
void deleteAtHead(node* &head)
{
    if(head != NULL)
    {
        head = head->next;
    }
}
void deleteAtTail(node* &head)
{
    node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete temp->next;
}
void deleteAtSpecificPosition(node* &head, int pos)
{
    int i = 1;
    node* temp = head;
    while(i < pos-1)
    {
        temp = temp->next;
        ++i;
    }
    node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}
void deleteAfterSpecificValue(node* &head, int value)
{
    int pos = searchElement(head, value);
    deleteAtSpecificPosition(head, pos);
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
    cout << "\n\n";
}
int main()
{
    node* head = NULL;

    cout << "Press 1 to Enter at Head" << endl;
    cout << "Press 2 to Enter at Tail" << endl;
    cout << "Press 3 to Enter desired Position" << endl;
    cout << "Press 4 to Find Length" << endl;
    cout << "Press 5 to Search Element From Unique Enabled List" << endl;
    cout << "Press 6 to Search Element From Duplicate Enabled List" << endl;
    cout << "Press 7 to Display list " << endl;
    cout << "Press 8 to insert after specific value" << endl;
    cout << "Press 9 to Delete at head" << endl;
    cout << "Press 10 to Delete at tail" << endl;
    cout << "Press 11 to Delete at specific Position" << endl;
    cout << "Press 12 to Delete after specific value" << endl;
    cout << "Press 0 to Exit" << endl;

    int choice;
    cout << "Enter From 0 - 7: ";
    cin >> choice;
    int data, key, pos, len;
    int* positions;
    while(choice != 0)
    {
        switch(choice)
        {
            case 1:
                cout << "Enter Data: ";
                cin >> data;
                insertAtHead(head, data);
                break;
            case 2:
                cout << "Enter Data: ";
                cin >> data;
                insertAtTail(head, data);
                break;
            case 3:
                cout << "Enter Data: ";
                cin >> data;
                cout << "Enter Position: ";
                cin >> pos;
                insertAtRandomPosition(head, pos, data);
                break;
            case 4:
                len = findLength(head);
                cout << "Length of Linked list now: " << len << endl;
                break;
            case 5:
                cout << "Enter Value you want to find: ";
                cin >> key;
                pos = searchElement(head, key);
                if(pos != -1)
                {
                    cout << key << " is at position " << pos << endl;
                }
                else
                {
                    cout << key << " not yet in the list" << endl;
                }
                break;
            case 6:
                cout << "Enter Value you want to find: ";
                cin >> key;
                positions = searchElementDuplicate(head, key);
                if(positions != NULL)
                {
                    cout << key << " is at ";
                    for(int i = 1; i <= positions[0]; i++)
                    {
                        cout << positions[i];
                        if(i < positions[0])
                        {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
                else
                {
                    cout << key << " not yet in the list" << endl;
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter specific value: ";
                cin >> pos;
                insertAfterSpecificValue(head, data, pos);
                break;
            case 9:
                deleteAtHead(head);
                break;
            case 10:
                deleteAtTail(head);
            case 11:
                cout << "Enter Position you want to delete: ";
                cin >> pos;
                deleteAtSpecificPosition(head, pos);
                break;
            case 12:
                cout << "Enter value: ";
                cin >> data;
                deleteAfterSpecificValue(head, data);
                break;
            default:
                break;
        }
        cout << "Enter from 0 - 8: ";
        cin >> choice;
    }
    cout << "After many types of operations: ";
    display(head);
    return 0;
}