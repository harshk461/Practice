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

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    vector<int> arr;
    ListNode *curr = head;
    while (curr != NULL)
    {
        arr.push_back(curr->val);
        curr = curr->next;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    ListNode *temp = NULL;
    for (auto i : arr)
    {
        ListNode *temp2 = new ListNode(i);
        temp2->next = temp;
        temp = temp2;
    }

    return temp;
}

ListNode *sortList2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
}

class Solution
{
private:
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        while (left != NULL && right != NULL)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        return dummy->next;
    }

    ListNode *mergeSort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *mid = getMid(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = NULL;

        l1 = mergesort(l1);
        l2 = mergeSort(l2);

        return merge(l1, l2);
    }

public:
    ListNode *sortList(ListNode *head)
    {

        return mergeSort(head);
    }
};

int main()
{

    return 0;
}