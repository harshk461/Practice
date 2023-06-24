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

bool checkPalindrome(vector<int> arr)
{
    int s = 0, e = arr.size() - 1;
    while (s < e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(ListNode *head)
{
    vector<int> st;
    ListNode *temp = head;
    while (temp != NULL)
    {
        st.push_back(temp->val);
        temp = temp->next;
    }

    return checkPalindrome(st);
}

// using stack
bool isPalindrome2(ListNode *head)
{
}
int main()
{

    return 0;
}