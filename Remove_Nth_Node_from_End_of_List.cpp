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

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *left = dummy;
        ListNode *right = head;

        while (n--)
        {
            right = right->next;
        }

        while (right != NULL)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy->next;
    }
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *result = new ListNode(0);
        result->next = head;
        int len = 0;
        ListNode *temp = result;
        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }
        if (len < n)
            return NULL;
        int index = len + 1 - n;
        len = 0;
        temp = result;
        while (temp->next != NULL)
        {
            len++;
            if (len == index)
            {
                temp->next = temp->next->next;
                return result->next;
            }
            temp = temp->next;
        }
        return result->next;
    }
};

int main()
{

    return 0;
}