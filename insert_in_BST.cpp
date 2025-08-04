#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_binary_tree()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(value);
    }

    queue<Node *> que;
    if (root)
    {
        que.push(root);
    }

    while (!que.empty())
    {
        Node *parent = que.front();
        que.pop();

        int left_val, right_val;
        cin >> left_val >> right_val;
        Node *myleft, *myRight;
        if (left_val == -1)
        {
            myleft = NULL;
        }
        else
        {
            myleft = new Node(left_val);
        }
        if (right_val == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(right_val);
        }

        parent->left = myleft;
        parent->right = myRight;

        if (parent->left)
        {
            que.push(parent->left);
        }
        if (parent->right)
        {
            que.push(parent->right);
        }
    }

    return root;
}

void level_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *parent = que.front();
        que.pop();

        cout << parent->value << " ";

        if (parent->left)
        {
            que.push(parent->left);
        }
        if (parent->right)
        {
            que.push(parent->right);
        }
    }
}

void insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
    }

    if (root->value > val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(val);
        }
        else
        {
            insert(root->left, val);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(val);
        }
        else
        {
            insert(root->right, val);
        }
    }
}

int main()
{

    Node *root = input_binary_tree();
    int val;
    cin >> val;
    insert(root, val);
    // insert(root, 11); //ak sathe value diye insert kora jai.
    level_order_traversal(root);

    return 0;
}

/*
input format : 10 6 23 -1 9 19 29 7 -1 12 -1 -1 35 -1 -1 -1 -1 -1 -1
insert----> 21
*/
