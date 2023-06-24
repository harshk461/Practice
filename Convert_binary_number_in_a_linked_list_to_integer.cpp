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
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
int getDecimalValue(ListNode *head)
{
    int ans = 0, power = length(head) - 1;
    ListNode *temp = head;
    while (temp != NULL)
    {
        ans += temp->val * pow(2, power);
        power--;
        temp = temp->next;
    }
    return ans;
}
int main()
{

    return 0;
}