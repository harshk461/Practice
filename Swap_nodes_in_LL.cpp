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

ListNode *swapNodes(ListNode *head, int k)
{
    vector<int> arr;
    while (head != NULL)
    {
        arr.push_back(head->val);
        head = head->next;
    }
    swap(arr[k - 1], arr[arr.size() - k]);
    head = NULL;
    reverse(arr.begin(), arr.end());
    for (auto i : arr)
    {
        ListNode *temp = new ListNode(i);
        temp->next = head;
        head = temp;
    }

    return head;
}

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *temp = head;
    int count = k;
    ListNode *r1 = head;
    Listnode *r2 = head;
    while (count--)
    {
        r1 = temp;
        temp = temp->next;
    }

    while (temp != NULL)
    {
        temp = temp->next;
        r2 = r2->next;
    }

    swap(r1->val, r2->val);
    return head;
}

int main()
{

    return 0;
}