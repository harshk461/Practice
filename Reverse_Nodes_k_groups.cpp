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
    ListNode *reverse(ListNode *head, ListNode *tail)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr != tail)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *tail = head;
        for (int i = 0; i < k; i++)
        {
            if (tail == NULL)
            {
                return head;
            }

            tail = tail->next;
        }

        ListNode *newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }
};
int main()
{

    return 0;
}