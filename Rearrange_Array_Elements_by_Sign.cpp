#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        queue<int> post;
        queue<int> neg;

        for (auto it : nums)
        {
            if (it >= 0)
                post.push(it);
            else
                neg.push(it);
        }

        vector<int> ans;
        while (!post.empty() || !neg.empty())
        {
            ans.push_back(post.front());
            ans.push_back(neg.front());
            post.pop(), neg.pop();
        }

        if (!post.empty())
            while (!post.empty())
            {
                ans.push_back(post.front());
                post.pop();
            }
        if (!neg.empty())
            while (!neg.empty())
            {
                ans.push_back(neg.front());
                neg.pop();
            }

        return ans;
    }
};

int main()
{

    return 0;
}