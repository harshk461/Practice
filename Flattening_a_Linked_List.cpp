#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *flatten(Node *root)
{
    vector<int> arr;
    while (root != NULL)
    {
        arr.push_back(root->data);
        Node *bottom = root->bottom;
        while (bottom != NULL)
        {
            arr.push_back(bottom->data);
            bottom = bottom->bottom;
        }
        root = root->next;
    }

    // for (auto it : arr)
    //     cout << it << " ";
    sort(arr.begin(), arr.end());

    Node *dummy = new Node(0);
    dummy->bottom = new Node(arr[0]);
    Node *temp = dummy->bottom;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->bottom = new Node(arr[i]);
        temp = temp->bottom;
    }
    return dummy->bottom;
}

int main()
{

    return 0;
}