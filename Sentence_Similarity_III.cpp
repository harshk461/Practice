#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution
{
private:
    vector<string> spilt(string s)
    {
        vector<string> arr;
        string curr = "";
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' ' || i == s.length())
            {
                arr.push_back(curr);
                curr = "";
            }
            else
                curr += s[i];
        }

        return arr;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);

        vector<string> arr1 = spilt(sentence1);
        vector<string> arr2 = spilt(sentence2);

        int n = arr1.size();
        int m = arr2.size();

        // for (auto it : arr1)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : arr2)
        //     cout << it << " ";

        int start = 0;
        int end = 0;

        while (start < m && arr1[start] == arr2[start])
            start++;

        while (end < m && arr1[n - end - 1] == arr2[m - end - 1])
            end++;
        // For the sentences to be considered similar, the total number of matching words
        // from the start and the end (start + end) must cover all the words in the shorter sentence
        return start + end >= m;
    }
};

int main()
{

    return 0;
}