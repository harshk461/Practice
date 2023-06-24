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
private:
    int length(ListNode *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }

public:
    ListNode *swapPairs(ListNode *head)
    {
        int n = length(head);
        ListNode *curr = head;
        ListNode dummy(0, head);
        ListNode *prev = &dummy;

        for (int i = 0; i < n / 2; i++)
        {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};
C

    ListNode *
    swapPairs(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        swap(temp->val, temp->next->val);
        temp = temp->next->next;
    }
    return head;
}
int main()
{

    return 0;
}