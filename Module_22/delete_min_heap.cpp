#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int val)
{
    int child_index = v.size() - 1;
    while (child_index != 0)
    {
        int parent_index = (child_index - 1) / 2;
        if (v[parent_index] > v[child_index])
        {
            swap(v[parent_index], v[child_index]);
        }
        else
        {
            break;
        }

        child_index = parent_index;
    }
}

void print_heap(vector<int> v)
{
    for (int res : v)
    {
        cout << res << " ";
    }

    cout << endl;
}

void delete_heap(vector<int> &v)
{
    v[0] = v.back();
    v.pop_back();
    int child_index = 0;
    while (true)
    {
        int left_index = child_index * 2 + 1;
        int right_index = child_index * 2 + 2;

        int left_val = INT_MAX;
        int right_val = INT_MAX;

        if (left_val < v.size())
        {
            left_val = v[left_index];
        }
        if (right_val < v.size())
        {
            right_val = v[right_index];
        }
        if (left_val <= right_val && left_val < v[child_index])
        {
            swap(v[left_index], v[child_index]);
            child_index = left_index;
        }
        else if (right_val < left_val && right_val < v[child_index])
        {
            swap(v[right_index], v[child_index]);
            child_index = right_index;
        }
        else
        {
            break;
        }
    }
}

int main()
{

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_heap(v, val);
    }

    print_heap(v);
    delete_heap(v);
    print_heap(v);

    return 0;
}

/*
input format : 11
21 17 9 13 11 42 6 2 3 7 5
*/