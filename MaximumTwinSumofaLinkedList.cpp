#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        this->val = value;
        this->next = NULL;
    }
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> arr;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int s = 0;
        int h = arr.size();
        int sum = 0;
        int init_sum;
        while (s < h)
        {
            init_sum = 0;
            init_sum = arr[s] + arr[h];
            if (init_sum > sum)
            {
                sum = init_sum;
            }
            s++;
            h--;
        }
        return sum;
    }
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> arr;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int s = 0;
        int h = arr.size() - 1;
        int sum = 0;
        int init_sum;
        while (s < h)
        {
            init_sum = 0;
            init_sum = arr[s] + arr[h];
            if (init_sum > sum)
            {
                sum = init_sum;
            }
            s++;
            h--;
        }
        return sum;
    }
};
int main()
{
    ListNode *root = new ListNode(5);
    root->next = new ListNode(4);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(1);

    cout << pairSum(root) << endl;
    return 0;
}