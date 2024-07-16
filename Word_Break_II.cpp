// #include <iostream>
// using namespace std;

// class Solution
// {
// private:
//     void createSubsets(int i, vector<vector<string>> &ans, vector<string> &temp, vector<string> &arr)
//     {
//         if (i >= arr.size())
//         {
//             ans.push_back(temp);
//             return;
//         }

//         // take
//         temp.push_back(arr[i]);
//         createSubsets(i + 1, ans, temp, arr);
//         temp.pop_back();

//         // not take
//         createSubsets(i + 1, ans, temp, arr);
//     }

//     string createString(vector<string> &arr)
//     {
//         string ans = "";
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if (i == arr.size() - 1)
//             {
//                 ans += arr[i];
//             }
//             else
//             {
//                 ans += arr[i] + " ";
//             }
//         }

//         return ans;
//     }

//     string mergeString(vector<string> &arr)
//     {
//         string ans = "";
//         for (auto it : arr)
//             ans += it;
//         return ans;
//     }

// public:
//     vector<string> wordBreak(string s, vector<string> &wordDict)
//     {
//         vector<vector<string>> subsets;
//         vector<string> temp;

//         createSubsets(0, subsets, temp, wordDict);

//         vector<string> ans;
//         for (auto it : subsets)
//         {
//             string s1 = mergeString(it);
//             if (s1 == s)
//             {
//                 string s2 = createString(it);
//                 ans.push_back(s2);
//             }
//         }

//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }

#include <iostream>
using namespace std;

class Solution
{
private:
    void solve(int index, string s, set<string> &wordSet, string &curr, vector<string> &ans)
    {
        if (index == s.length())
        {
            ans.push_back(curr);
            return;
        }

        for (int end = index + 1; end <= s.length(); end++)
        {
            string word = s.substr(index, end - index);

            if (wordSet.find(word) != wordSet.end())
            {
                string originalSentence = curr;

                if (!curr.empty())
                    curr += " ";

                curr += word;

                solve(end, s, wordSet, curr, ans);

                curr = originalSentence;
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> ans;

        string curr;

        solve(0, s, wordSet, curr, ans);

        return ans;
    }
};

int main()
{

    return 0;
}