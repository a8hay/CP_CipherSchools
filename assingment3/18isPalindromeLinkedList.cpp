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

Node *findMid(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL, *Next = NULL;
    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

Node *reverseListRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *mid = findMid(head);
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

int main()
{
    Node *ll = new Node(1);
    ll->next = new Node(2);
    ll->next->next = new Node(13);
    ll->next->next->next = new Node(4);
    ll->next->next->next->next = new Node(5);
    Node *curr = reverseListRecursive(ll);
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}