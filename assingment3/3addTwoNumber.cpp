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

Node *addTwoNumber(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *dummy = new Node();
    Node *result = dummy, *ptra = a, *ptrb = b;
    int carry = 0, sum = 0;
    while (ptra != NULL || ptrb != NULL)
    {
        sum = (ptra != NULL ? ptra->data : 0) + (ptrb != NULL ? ptrb->data : 0) + carry;
        carry = sum / 10;
        sum = sum % 10;
        result->next = new Node(sum);
        result = result->next;
        if (ptra != NULL)
        {
            ptra = ptra->next;
        }
        if (ptrb != NULL)
        {
            ptrb = ptrb->next;
        }
    }
    if (carry > 0)
    {
        result->next = new Node(carry);
    }
    return dummy->next;
}

int main()
{
    return 0;
}