class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> map;
        unordered_map<int, int> map2;
        for (auto it : arr1)
            map[it]++;

        for (auto it : arr2)
            map2[it]++;

        vector<int> ans;
        vector<int> rem;

        for (auto it : arr1)
            if (map2[it] == 0)
                rem.push_back(it);
        for (auto it : arr2)
        {
            while (map[it])
            {
                ans.push_back(it);
                map[it]--;
            }
        }
        sort(rem.begin(), rem.end());
        for (auto it : rem)
            ans.push_back(it);

        return ans;
    }
};