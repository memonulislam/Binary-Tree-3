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

Node *convert_array(int arr[], int n, int myLeft, int myRight)
{
    if (myLeft > myRight)
    {
        return NULL;
    }

    int mid = (myLeft + myRight) / 2;

    Node *root = new Node(arr[mid]);
    Node *leftRoot = convert_array(arr, n, myLeft, mid - 1);
    Node *rightRoot = convert_array(arr, n, mid + 1, myRight);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = convert_array(arr, n, 0, n - 1);
    level_order_traversal(root);

    return 0;
}

/*
 input give : 6
 input format : 2 5 8 11 15 18
 output format : 8 2 15 5 11 18
*/
