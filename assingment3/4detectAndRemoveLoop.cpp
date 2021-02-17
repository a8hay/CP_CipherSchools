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

bool detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    Node *slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

Node *detectAndRemoveLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *slow = head, *fast = head;
    bool loopPresent = false;
    while (slow != NULL && fast != NULL and fast->next != NULl)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            loopPresent = true;
            break;
        }
    }
    if (loopPresent)
    {
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    fast->next = NULL;
}

int main()
{
    return 0;
}
