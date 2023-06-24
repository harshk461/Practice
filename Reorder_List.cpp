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
    ListNode *findMid(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            curr = prev;
            curr = next;
        }

        return prev;
    }

    void merge(ListNode *l1, ListNode *l2)
    {
        while (l2)
        {
            ListNode *next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    }

public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return NULL;
        }

        ListNode *mid = findMid(head);
        ListNode *reversed = reverse(mid);
        merge(head, reversed);
    }
};

int main()
{

    return 0;
}