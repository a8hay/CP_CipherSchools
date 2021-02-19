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

Node *rearrange(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *ptr = head, *next = NULL, *prev = NULL;
    Node dummy;
    Node *even = &dummy;
    // bool isOdd = true;
    while (ptr != NULL)
    {
        prev = ptr;
        next = ptr->next;
        ptr->next = next->next;
        even->next = next;
        even = even->next;
        ptr = ptr->next;
    }
    prev->next = dummy.next;
    return head;
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
    Node *ll = new Node(1);
    ll->next = new Node(2);
    ll->next->next = new Node(12);
    ll->next->next->next = new Node(14);
    ll->next->next->next->next = new Node(15);
    ll->next->next->next->next->next = new Node(51);
    ll->next->next->next->next->next->next = new Node(45);
    ll->next->next->next->next->next->next->next = new Node(61);

    printList(ll);
    printList(rearrange(ll));
    return 0;
}