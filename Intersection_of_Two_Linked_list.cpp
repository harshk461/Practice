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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != b)
    {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main()
{

    return 0;
}