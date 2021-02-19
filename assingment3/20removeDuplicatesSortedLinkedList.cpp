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
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    Node *nxt = NULL;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            nxt = curr->next;
            curr->next = nxt->next;
            delete nxt;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
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