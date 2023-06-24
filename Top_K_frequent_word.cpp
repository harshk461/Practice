#include <bits/stdc++.h>
using namespace std;

class compare
{
public:
    bool operator()(pair<int, string> pair1, pair<int, string> pair2)
    {

        if (pair1.first != pair2.first)
            return pair1.first < pair2.first;
        else
            return pair1.second >= pair2.second;
    }
};
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        unordered_map<string, int> umap;

        for (string word : words)
            umap[word]++;

        for (auto itr = umap.begin(); itr != umap.end(); itr++)
        {
            pq.push(make_pair(itr->second, itr->first));
        }

        vector<string> freqWords;

        while (k > 0)
        {
            freqWords.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return freqWords;
    }
};

int main()
{
    vector<string> arr = {"i", "love", "leetcode", "i", "love", "coding"};
    return 0;
}