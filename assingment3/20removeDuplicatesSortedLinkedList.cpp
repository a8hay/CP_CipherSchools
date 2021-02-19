#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        Node(0);
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "\n";
}

Node *removeDuplicate(Node *head)
{
    Node *dummy = new Node(-1);
    Node *dummy_tail = dummy, *curr = head;
    while (curr != NULL)
    {
        if (curr->data != dummy_tail->data)
        {
            dummy_tail->next = curr;
            dummy_tail = dummy_tail->next;
        }
        curr = curr->next;
    }
    return dummy->next;
}

int main()
{
    Node *ll = new Node(1);
    ll->next = new Node(2);
    ll->next->next = new Node(2);
    ll->next->next->next = new Node(4);
    ll->next->next->next->next = new Node(15);
    ll->next->next->next->next->next = new Node(15);
    ll->next->next->next->next->next->next = new Node(15);
    ll->next->next->next->next->next->next->next = new Node(61);

    printList(ll);
    printList(removeDuplicate(ll));
    return 0;
}