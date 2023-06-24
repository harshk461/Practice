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

vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> ans;
    stack<int> st;

    for (; head; head = head->next)
    {
        while (!st.empty() && head->val > ans[st.top()])
        {
            int index = st.top();
            st.pop();
            ans[index] = head->val;
        }
        st.push(ans.size());
        ans.push_back(head->val);
    }

    for (; !st.empty(); st.pop())
    {
        ans[st.top()] = 0;
    }
    return ans;
}

int main()
{

    return 0;
}