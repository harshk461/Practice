class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        int j = 0, n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != temp[j])
                ans++;
            j++;
        }

        return ans;
    }
};