#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
private:
    vector<pair<int, int>> brute(Node *head, int target)
    {
        vector<int> arr;
        unordered_map<int, int> freq;
        while (head != NULL)
        {
            arr.push_back(head->data);
            freq[head->data]++;
            head = head->next;
        }
        set<pair<int, int>> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            int new_tar = target - arr[i];
            freq[arr[i]]--;
            if (freq[new_tar] > 0)
            {
                if (arr[i] < new_tar)
                    ans.insert({arr[i], new_tar});
                else
                    ans.insert({new_tar, arr[i]});
            }
            freq[arr[i]]++;
        }

        vector<pair<int, int>> res(ans.begin(), ans.end());
        return res;
    }

    vector<pair<int, int>> solve(Node *head, int target)
    {
        Node *left = head;
        Node *right = head;

        while (right->next != NULL)
            right = right->next;
        vector<pair<int, int>> ans;
        while (left != right)
        {
            if (left->data + right->data > target)
                right = right->prev;
            else if (left->data + right->data < target)
                left = left->next;

            else
            {
                ans.push_back({left->data, right->data});
                left = left->next;
            }
        }
        return ans;
    }

public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        return solve(head, target);
    }
};

int main()
{

    return 0;
}