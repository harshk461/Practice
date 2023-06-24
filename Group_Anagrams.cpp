#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
        string key = strs[i];
        sort(key.begin(), key.end());
        map[key].push_back(strs[i]);
    }
    for (const auto &[_, anagrams] : map)
        ans.push_back(anagrams);
    return ans;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<string> temp_arr = strs;
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> map;
    for (int i = 0; i < strs.size(); i++)
    {
        sort(strs[i].begin(), strs[i].end());
        vector<int> temp = map[strs[i]];
        temp.push_back(i);
        map[strs[i]] = temp;
    }
    for (auto i : map)
    {
        vector<int> arr = i.second;
        vector<string> arr2;
        for (auto i : arr)
        {
            arr2.push_back(temp_arr[i]);
        }
        ans.push_back(arr2);
    }
    return ans;
}

int main()
{
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(arr);
    return 0;
}