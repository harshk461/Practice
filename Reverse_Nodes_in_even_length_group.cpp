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
    ListNode *reverse(ListNode *head, int k)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head;
    }

    pair<ListNode *, int> getTailAndLength(ListNode *head, int groupLength)
    {
        int len = 1;
        ListNode *tail = head;
        while (length < groupLength && tail->next)
        {
            tail = tail->next;
            len++;
        }
        return {tail, len};
    }

public:
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *tail = head;
        ListNode *next = head->next;
        int groupLen = 1;

        while (true)
        {
            if (groupLen & 1)
            {
                prev->next = head;
                prev = tail;
            }
            else
            {
                tail->next = NULL;
                prev->next = reverse(head);
                head->next = next;
                prev = head;
            }

            if (next == NULL)
            {
                break;
            }

            head = next;
            const auto [theTail, Length] = getTailAndLength(head, groupLen + 1);
            tail = theTail;
            next = tail->next;
            groupLen = Length
        }
        return dummy.next;
    }
};

int main()
{

    return 0;
}