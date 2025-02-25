#include <bits/stdc++.h>
using namespace std;

// Fast I/O optimization to speed up input/output operations
auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    /**
     * Recursive function to construct the distanced sequence.
     * @param i     - Current index in the sequence
     * @param n     - The maximum number to be placed
     * @param ans   - The sequence being constructed
     * @param vis   - A boolean array to track used numbers
     * @return      - True if a valid sequence is found, otherwise false
     */
    bool solve(int i, int n, vector<int> &ans, vector<bool> &vis)
    {
        // If we have filled the entire sequence, return true
        if (i >= ans.size())
            return true;

        // If the current position is already occupied, move to the next index
        if (ans[i] != -1)
            return solve(i + 1, n, ans, vis);

        // Try placing numbers from n down to 1 (larger numbers first for efficiency)
        for (int num = n; num >= 1; num--)
        {
            if (vis[num]) // If the number is already used, skip it
                continue;

            // Mark the number as used
            vis[num] = true;
            ans[i] = num;

            // If placing `num` at index `i` is valid:
            // - If num == 1, it only occupies one position
            // - If num > 1, it must also be placed at (i + num)
            if (num == 1 || (i + num < ans.size() && ans[i + num] == -1))
            {
                if (num > 1) // Place the second occurrence of num
                    ans[i + num] = num;

                // Recursively try to fill the next position
                if (solve(i + 1, n, ans, vis))
                    return true;

                // Backtrack if no valid sequence is found
                if (num > 1)
                    ans[i + num] = -1;
            }

            // Undo the choice and mark the number as unused
            vis[num] = false;
            ans[i] = -1;
        }
        return false;
    }

public:
    /**
     * Generates a distance-based sequence of size `2 * n - 1`
     * where each number appears exactly twice, at `i` and `i + num` positions.
     * @param n - The maximum number to be placed in the sequence
     * @return  - A valid sequence following the constraints
     */
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(2 * n - 1, -1); // Initialize sequence with -1
        vector<bool> vis(n + 1, false); // Tracks which numbers have been used

        // Start solving from index 0
        solve(0, n, ans, vis);

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<int> result = sol.constructDistancedSequence(n);

    // Print the result
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
