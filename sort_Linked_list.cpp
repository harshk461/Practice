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

int main()
{

    return 0;
}