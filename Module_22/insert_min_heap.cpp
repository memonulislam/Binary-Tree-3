#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int val;
    cin >> val;
    v.push_back(val);

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

    for (int res : v)
    {
        cout << res << " ";
    }

    cout << endl;

    return 0;
}

/*
input format :
10
10 2 3 9 13 4 11 1 7 5
6
*/