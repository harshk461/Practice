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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode dummy(0, head);
    ListNode *prev = &dummy;
    for (; head; head = head->next)
        if (head->val != val)
        {
            prev->next = head;
            prev = prev->next;
        }
    prev->next = NULL;
    return dummy.next;
}

int main()
{

    return 0;
}