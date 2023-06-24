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

ListNode *insertionSortList(ListNode *head)
{
    ListNode dummy(0);
    ListNode *prev = &dummy;
    while (head)
    {
        ListNode *next = head->next;
        if (prev->val >= head->val)
        {
            prev = &dummy;
        }
        while (prev->next && prev->next->val < head->val)
        {
            prev = prev->next;
        }

        head->next = prev->next;
        prev->next = head;
        head = next;
    }
    return dummy.next;
}
int main()
{

    return 0;
}