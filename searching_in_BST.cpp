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
        Node *p = que.front();
        que.pop();

        int left_val, right_val;
        cin >> left_val >> right_val;

        Node *myLeft, *myRight;
        if (left_val == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(left_val);
        }
        if (right_val == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(right_val);
        }

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
        {
            que.push(p->left);
        }
        if (p->right)
        {
            que.push(p->right);
        }
    }

    return root;
};

bool search(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->value == val)
    {
        return true;
    }

    if (root->value > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

int main()
{

    Node *root = input_binary_tree();
    int val;
    cin >> val;
    if (search(root, val))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}

/*
 input format : 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1 ----->

--------> search korbo paile found hobe for example 12 found ahsbe <---------
 -------> search kore na paile not found hobe for example 16 not found ahsbe <---------

*/