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

Node *removeDuplicate(Node *head)
{
    Node *dummy = new Node();
    dummy->next = head;
    Node *prev = dummy, *curr = head;
    while (curr != NULL)
    {
        while (curr->next != NULL && prev->next->data == curr->next->data)
            curr = curr->next;

        if (prev->next == curr)
            prev = prev->next;
        else
            prev->next = curr->next;

        curr = curr->next;
    }
    return dummy->next;
}

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

int main()
{
    Node *ll = new Node(23);
    ll->next = new Node(28);
    ll->next->next = new Node(28);
    ll->next->next->next = new Node(35);
    ll->next->next->next->next = new Node(49);
    ll->next->next->next->next->next = new Node(49);
    ll->next->next->next->next->next->next = new Node(53);
    ll->next->next->next->next->next->next->next = new Node(53);

    printList(ll);
    printList(removeDuplicate(ll));
    return 0;
}