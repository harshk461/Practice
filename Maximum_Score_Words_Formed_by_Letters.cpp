// #include <iostream>
// using namespace std;

// class Solution
// {
// private:
//     void createAllSubsets(int i, vector<string> &words, vector<vector<string>> &ans, vector<string> &temp)
//     {
//         if (i == words.size())
//         {
//             ans.push_back(temp);
//             return;
//         }

//         // take
//         temp.push_back(words[i]);
//         createAllSubsets(i + 1, words, ans, temp);
//         temp.pop_back();

//         // not take
//         createAllSubsets(i + 1, words, ans, temp);
//     }

//     unordered_map<char, int> createMapOfWordArray(vector<string> words)
//     {
//         unordered_map<char, int> map;
//         for (auto it : words)
//         {
//             for (auto i : it)
//                 map[i]++;
//         }

//         return map;
//     }

//     int brute(vector<string> &subset, unordered_map<char, int> &map, vector<int> &scores)
//     {
//         unordered_map<char, int> temp_map = createMapOfWordArray(subset);

//         cout << endl;
//         for (auto it : temp_map)
//             cout << it.first << " " << it.second << endl;

//         int ans = 0;
//         for (int i = 0; i < 26; i++)
//         {
//             if (map['a' + i] != temp_map['a' + i])
//                 return 0;
//         }

//         for (auto it : subset)
//         {
//             for (auto i : it)
//             {
//                 ans += scores[i];
//             }
//         }

//         return ans;
//     }

// public:
//     int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
//     {
//         vector<vector<string>> subsets;
//         vector<string> temp;

//         createAllSubsets(0, words, subsets, temp);

//         // for (auto it : subsets)
//         // {
//         //     for (auto i : it)
//         //         cout << i << " ";
//         //     cout << endl;
//         // }

//         unordered_map<char, int> letter_map;
//         for (auto it : letters)
//             letter_map[it]++;

//         int ans = 0;
//         for (auto it : letter_map)
//             cout << it.first << " " << it.second << endl;

//         vector<string> t={"dad","good"};
//         brute(t, letter_map, score);
//         // for (auto it : subsets)
//         //     ans = max(ans, brute(it, letter_map, score));
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
    void solve(int i, int &ans, int curr, vector<string> &words, unordered_map<char, int> &map, vector<int> &score)
    {
        ans = max(ans, curr);
        if (i >= words.size())
            return;

        // we have to check that can we fit the word in the answer
        unordered_map<char, int> temp = map;
        int s = 0; // curr score
        int j = 0;
        while (j < words[i].length())
        {
            char posn = words[i][j];
            temp[posn]--;

            s += score[posn - 'a'];

            if (temp[posn] < 0)
                break;

            j++;
        }

        // if we can reach the end of the word this mean that we can add the score in the ans
        // and we have to give the temp map as the paramerter
        if (j == words[i].length())
            solve(i + 1, ans, curr + s, words, temp, score);

        // else we have to proceed without adding the score
        solve(i + 1, ans, curr, words, map, score);
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        unordered_map<char, int> map;
        for (auto it : letters)
            map[it]++;

        int ans = INT_MIN;
        int curr = 0;

        solve(0, ans, curr, words, map, score);

        return ans;
    }
};

int main()
{

    return 0;
}