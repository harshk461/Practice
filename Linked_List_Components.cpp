#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int numComponents(ListNode *head, vector<int> &nums)
{
    int ans = 0;
    unordered_set<int> setNums(nums.begin(), nums.end())
    {
        for (; head; head = head->next)
        {
            if (setNums.count(head->val) && (!head->next || !setNums.count(head->next->val)))
                ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}