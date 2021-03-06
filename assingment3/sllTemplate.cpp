#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        this->head = NULL;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node *curr = this->head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    int getSize()
    {
        int size = 0;
        Node *curr = this->head;
        while (curr != NULL)
        {
            size += 1;
            curr = curr->next;
        }
        return size;
    }

    void printList()
    {
        Node *curr = this->head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.insertAtBeginning(5);
    sll.insertAtBeginning(3);
    sll.insertAtBeginning(4);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(1);
    sll.printList();
    cout << sll.getSize() << endl;
    return 0;
}