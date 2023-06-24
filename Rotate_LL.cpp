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

ListNode *rotateRight(ListNode *head, int k)
{
    ListNode *slow = head;
    ListNode *fast = head;

    if (head == NULL)
    {
        return head;
    }

    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    k = k % count;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = head;
    ListNode *result = slow->next;
    slow->next = NULL;
    return result;
}

int main()
{

    return 0;
}