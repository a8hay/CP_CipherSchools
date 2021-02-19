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

Node *reverseLinkedListInGroup(Node *head, int K)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head, *prev = NULL, *next = NULL;
    int k = 0;
    while (curr != NULL && k < K)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k++;
    }
    Node *newHead = reverseLinkedListInGroup(next, k);
    head->next = newHead;
    return prev;
}

int main()
{
    Node *ll = new Node(1);
    ll->next = new Node(2);
    ll->next->next = new Node(13);
    ll->next->next->next = new Node(4);
    ll->next->next->next->next = new Node(15);
    ll->next->next->next->next->next = new Node(6);
    ll->next->next->next->next->next->next = new Node(5);
    ll->next->next->next->next->next->next->next = new Node(51);
    int k = 3;
    Node *curr = reverseLinkedListInGroup(ll, k);
    // Node *curr = ll;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}