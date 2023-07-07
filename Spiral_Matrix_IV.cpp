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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<int> dirs{0, 1, 0, -1, 0};

        int x = 0; // curr x
        int y = 0; // curr y
        int d = 0;

        for (ListNode *curr = head; curr; curr = curr->next)
        {
            ans[x][y] = curr->val;
            if (x + dirs[d] < 0 || x + dirs[d] == m || y + dirs[d + 1] < 0 ||
                y + dirs[d + 1] == n || ans[x + dirs[d]][y + dirs[d + 1]] != -1)
            {
                d = (d + 1) % 4;
            }
            x += dirs[d];
            y += dirs[d + 1];
        }

        return ans;
    }
};

int main()
{
    cout << 2 % 4 << " ";
    return 0;
}