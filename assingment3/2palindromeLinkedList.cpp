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

    Node *findMid()
    {
        Node *slow = this->head, *fast = this->head;
        if (this->head == NULL || this->head->next == NULL)
        {
            return head;
        }
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome()
    {
        if (this->head == NULL || this->head->next == NULL)
            return true;
        Node *mid = findMid();
        Node *reversedMid = reverseList(mid->next);
        Node *p = head, *q = reversedMid;
        while (p != NULL && q != NULL)
        {
            if (p->data != q->data)
            {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *next = reverseList(head->next);
    next->next = head;
    head->next = NULL;
    return head;
}

int main()
{
    SinglyLinkedList sll;
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(1);
    sll.printList();
    cout << sll.isPalindrome() << endl;
    return 0;
}