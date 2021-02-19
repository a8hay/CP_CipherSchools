#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void range(Node *root, int start, int end, vector<int> &result)
{
    if (root == NULL)
        return;

    if (root->data >= start && root->data <= end)
        result.push_back(root->data);
    if (root->data < start)
        range(root->right, start, end, result);
    else if (root->data > end)
        range(root->left, start, end, result);
    else
    {
        range(root->right, start, end, result);
        range(root->left, start, end, result);
    }
}

void findRange(Node *root, int start, int end)
{
    vector<int> result;
    range(root, start, end, result);
    for (int a : result)
        cout << a << " ";
    cout << endl;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->left->right = new Node(6);
    root->left->left->right->left = new Node(5);
    root->left->right = new Node(9);
    root->right = new Node(13);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    root->right->right->left = new Node(16);
    root->right->right->right = new Node(21);

    findRange(root, 5, 10);
    return 0;
}