#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *ans = head;
        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != NULL)
        {
            int gcd = __gcd(prev->val, curr->val);
            ListNode *node = new ListNode(gcd);
            prev->next = node;
            node->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return ans;
    }
};

int main()
{

    return 0;
}