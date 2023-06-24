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

ListNode *removeNodes(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    head->next = removeNodes(head->next);
    return head->next != NULL && head->val < head->next->val ? head->next : head;
}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return head;
}

ListNode *removeNodes(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *curr = reverse(head);
    ListNode *ans = curr;
    int val = curr->val;

    while (curr && curr->next)
    {

        while (curr && curr->next && curr->next->val < val)
        {
            curr = curr->next;
        }

        if (curr && curr->next)
        {
            val = max(val, curr->val);
            curr = curr->next;
        }
    }
    return ans;
}

int main()
{

    return 0;
}