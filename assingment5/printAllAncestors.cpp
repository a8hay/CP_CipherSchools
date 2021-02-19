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

bool findAncestors(Node *root, Node *x, vector<int> &path)
{
    if (root == NULL)
        return false;
    if (root == x)
    {
        path.push_back(x->data);
        return true;
    }
    path.push_back(root->data);
    if ((root->left != NULL) && findAncestors(root->left, x, path))
        return true;
    if ((root->right != NULL) && findAncestors(root->right, x, path))
        return true;

    // backtrack
    path.pop_back();
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    Node *a = root->right->left->left = new Node(6);
    root->right->right = new Node(5);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->left = new Node(9);
    vector<int> path;
    findAncestors(root, a, path);
    for (int a : path)
        cout << a << " ";
    cout << endl;
    return 0;
}