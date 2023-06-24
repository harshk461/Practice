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

int getLen(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

vector<ListNode *> splitListToParts(ListNode *root, int k)
{
    vector<ListNode *> ans(k);
    int len = getLen(root);
    int sublen = len / k;
    int remainder = len % k;

    ListNode *prev = NULL;
    ListNode *head = root;

    for (int i = 0; i < k; i++, --remainder)
    {
        ans[i] = head;
        for (int j = 0; j < sublen + (remainder > 0); j++)
        {
            prev = head;
            head = head->next;
        }
        if (prev != NULL)
        {
            prev->next = NULL;
        }
    }
    return ans;
}

int main()
{

    return 0;
}