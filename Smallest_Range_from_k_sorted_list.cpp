#include <bits/stdc++.h>

class node
{
    int data;
    int row;
    int col;

    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
}

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
}

int
kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;
}

int main()
{
    return 0;
}