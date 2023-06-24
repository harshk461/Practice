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
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> arr;
        for (auto node : lists)
        {
            while (node)
            {
                arr.push_back(node->val);
                node = node->next;
            }
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        ListNode *newhead = NULL;
        for (auto i : arr)
        {
            ListNode *temp = new ListNode(i);
            temp->next = newhead;
            newhead = temp;
        }

        return newhead;
    }

    // using divide and conquer and prioity queue
    ListNode *mergeKLists2(vector<ListNode *> &lists)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        auto compare = [](ListNode *a, ListNode *b)
        { return a->val > b->val };
        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> minHeap(
            compare);
        for (ListNode *list : lists)
        {
            if (list != NULL)
                minheap.push(list);
        }

        while (!minheap.empty())
        {
            ListNode *minNode = minheap.top();
            minheap.pop();

            if (minNode->next)
            {
                minheap.push(minNode->next);
            }
            curr->next = minNode;
            curr = curr->next;
        }
        return dummy.next;
    }
};

int main()
{

    return 0;
}