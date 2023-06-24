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

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    int minDistance = INT_MAX;
    int firstIndex = -1;
    int prevIndex = -1;

    int index = 1;

    ListNode *prev = head;
    ListNode *curr = head->next;

    while (curr->next)
    {
        if (curr->val > prev->val && curr->val > curr->next->val ||
            curr->val < prev->val && curr->val < curr->next->val)
        {
            if (firstIndex == -1) // only assign once
                firstIndex = index;
            if (prevIndex != -1)
                minDistance = min(minDistance, index - prevIndex);
            prevIndex=index;
        }
        prev = curr;
        curr = curr->next;
        ++index;
    }

    if (minDistance == INT_MAX)
        return {-1, -1};
    return (minDistance, prevIndex - firstIndex);
}
int main()
{

    return 0;
}