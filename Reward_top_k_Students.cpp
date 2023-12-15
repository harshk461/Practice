#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> spiltSentence(string str)
    {
        vector<string> ans;
        string word = "";
        for (auto x : str)
        {
            if (x == ' ')
            {
                ans.push_back(word);
                word = "";
            }
            else
                word = word + x;
        }
        ans.push_back(word);
        return ans;
    }

public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        unordered_map<string, bool> positive;
        unordered_map<string, bool> negative;

        for (auto pt : positive_feedback)
            positive[pt] = true;
        for (auto ng : negative_feedback)
            negative[ng] = true;

        // map->{student_id,score}
        // score=3*positive-1*negative
        vector<pair<int, int>> scores;

        int index = 0;
        while (index < student_id.size())
        {
            // count score
            string rep = report[index];
            vector<string> rep_vector = spiltSentence(rep);

            // positive and negative
            int positiveScore = 0;
            int negativeScore = 0;

            for (auto it : rep_vector)
            {
                if (positive[it] == true)
                    positiveScore++;
                if (negative[it] == true)
                    negativeScore++;
            }

            int totalScore = 3 * positiveScore - 1 * negativeScore;
            scores.push_back({student_id[index], totalScore});

            index++;
        }

        sort(scores.begin(), scores.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             {
    if (a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    } });

        vector<int> ans;
        int i = 0;
        while (i < k)
        {
            ans.push_back(scores[i].first);
            i++;
        }

        return ans;
    }
};

int main()
{
    vector<string> positive_feedback = {"smart", "brilliant", "studious"};
    vector<string> negative_feedback = {"not"};
    vector<string> report = {"this student is not studious", "the student is smart"};
    vector<int> studednt = {1, 2};
    int k = 2;

    Solution s;
    vector<int> ans = s.topStudents(positive_feedback, negative_feedback, report, studednt, k);
    for (auto it : ans)
        cout << it << ' ';
    return 0;
}