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

Node *intersectionPointLinkedList(Node *head1, Node *head2)
{
    Node *a = head1, *b = head2;
    if (a == NULL || b == NULL)
        return NULL;

    while (a != b)
    {
        a = a->next;
        b = b->next;
        if (a == b)
            return a;
        if (a == NULL)
        {
            a = head2;
        }
        if (b == NULL)
        {
            b = head1;
        }
    }
    return a;
}

int main()
{
    return 0;
}