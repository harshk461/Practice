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
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *solve(ListNode *head)
    {
        // reverse ll
        head = reverse(head);

        int carry = 0;

        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            int sum = temp->val * 2;
            int num = sum % 10;

            temp->val = num + carry;
            carry = sum / 10;

            prev = temp;
            temp = temp->next;
        }

        if (carry > 0)
        {
            ListNode *nn = new ListNode(carry);
            prev->next = nn;
        }

        head = reverse(head);

        return head;
    }

public:
    ListNode *doubleIt(ListNode *head)
    {
        return solve(head);
    }
};

int main()
{

    return 0;
}