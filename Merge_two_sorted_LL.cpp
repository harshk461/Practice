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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1 || !list2)
    {
        return list1 ? list1 : list2;
    }

    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }

    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
}

int main()
{

    return 0;
}