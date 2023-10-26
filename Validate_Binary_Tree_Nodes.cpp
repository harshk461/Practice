#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1)
        {
            return false;
        }

        unordered_set<int> seen;
        stack<int> stack;
        seen.insert(root);
        stack.push(root);

        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();

            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children)
            {
                if (child != -1)
                {
                    if (seen.find(child) != seen.end())
                    {
                        return false;
                    }

                    stack.push(child);
                    seen.insert(child);
                }
            }
        }

        return seen.size() == n;
    }

    int solve(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                indegree[leftChild[i]]++;
            if (rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }

        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                if (root == -1)
                    root = i;
                else
                    return false;
            }
        }

        if (root == -1)
            return false;

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (visited[node])
                return false;
            visited[node] = true;
            if (leftChild[node] != 1)
                q.push(leftChild[node]);
            if (rightChild[node] != -1)
                q.push(rightChild[node]);
        }

        return accumulate(visited.begin(), visited.end(), 0) == n;
    }

    int findRoot(int n, vector<int> &left, vector<int> &right)
    {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());

        for (int i = 0; i < n; i++)
        {
            if (children.find(i) == children.end())
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}