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

class Solution
{
public:
    ListNode *root;
    Solution(ListNode *head)
    {
        root(head);
    }

    int getRandom()
    {
        int ans = -1;
        int i = 1;

        for (ListNode *curr = head; curr; curr = curr->next, i++)
        {
            if (rand() % i == 0)
            {
                ans = curr->val;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}