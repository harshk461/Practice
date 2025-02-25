#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        Node *dummy = head;
        while (dummy != NULL)
        {
            Node *curr = dummy;

            while (curr->next != NULL && curr->next->data == curr->data)
                curr = curr->next;

            dummy->next = curr->next;
            curr->prev = dummy;
        }

        return head;
    }
};

int main()
{

    return 0;
}