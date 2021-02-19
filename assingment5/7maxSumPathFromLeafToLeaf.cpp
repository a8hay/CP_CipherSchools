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

int maxSumPath(Node *root)
{

    return 26;
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

    cout << maxSumPath(root) << endl;

    return 0;
}