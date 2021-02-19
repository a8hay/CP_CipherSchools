#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data = 0)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}

void printGivenLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    int levels = height(root);
    for (int level = 1; level <= levels; level++)
    {
        printGivenLevel(root, level);
    }
}

void levelOrderTraversalLineByLine(Node *root)
{
    if (root == NULL)
        return;
    int levels = height(root);
    for (int level = 1; level <= levels; level++)
    {
        printGivenLevel(root, level);
        cout << endl;
    }
}

void levelOrderTraversalIterative(Node *root)
{
    queue<Node *> q;
    q.push(root);
    Node *curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

void levelOrderTraversalIterativeLineByLine(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    Node *curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (q.empty())
            {
                cout << "\n";
                return;
            }
            else
            {
                q.push(NULL);
                cout << "\n";
            }
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
}

void reverseLevelOrderTraversalIterativeLineByLine(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    q.push(NULL);
    Node *curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (q.empty())
            {
                return;
            }
            else
            {
                q.push(NULL);
                s.push(NULL);
            }
        }
        else
        {
            s.push(curr);
            if (curr->right)
                q.push(curr->right);
            if (curr->left)
                q.push(curr->left);
        }
    }
    while (!s.empty())
    {
        curr = s.top();
        s.pop();
        if (curr == NULL)
            cout << "\n";
        else
            cout << curr->data;
    }
}

void spiralTraverse(Node *root)
{
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(6);
    root->right->right = new Node(5);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->left = new Node(9);

    spiralTraverse(root);

    return 0;
}