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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *newList(0);
    ListNode *pre = newList;
    ListNode *curr;
    newList->next = head;
    for (int i = 0; i < left - 1; i++)
    {
        pre = pre->next;
    }

    curr = pre->next;
    for (int i = 0; i < right - left; i++)
    {
        ListNode *temp = pre->next;
        pre->next = curr->next;
        curr->next = curr->next->next;
        pre->next->next = temp;
    }
    return newList->next;
}
int main()
{

    return 0;
}