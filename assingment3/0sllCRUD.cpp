#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
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

    void insertAtFront(int data)
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
            curr = curr->next;
            size += 1;
        }
        return size;
    }

    void removeFromFront()
    {
        if (this->head == NULL)
        {
            return;
        }
        Node *currHead = this->head;
        this->head = this->head->next;
        delete currHead;
    }

    void removeFromEnd()
    {
        if (this->head == NULL)
        {
            return;
        }
        if (this->head->next == NULL)
        {
            Node *currHead = this->head;
            this->head = this->head->next;
            delete currHead;
            return;
        }
        Node *curr = this->head, *prev = NULL;
        while (curr->next != NUll)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }

    int getFirst()
    {
        if (this->head == NULL)
        {
            return -1;
        }
        else
        {
            return this->head->data;
        }
    }
};

int main()
{
    return 0;
}