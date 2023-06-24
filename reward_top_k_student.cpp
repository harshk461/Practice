#include <bits/stdc++.h>
using namespace std;

vector<string> wordSplit(string word)
{
    vector<string> arr;
    string word_temp = "";
    for (int i = 0; i <= word.length(); i++)
    {
        if (word[i] == ' ' || i == word.length())
        {
            arr.push_back(word_temp);
            word_temp = "";
        }
        else
        {
            word_temp = word_temp + word[i];
        }
    }
    return arr;
}

bool checkInArray(string word, vector<string> word_array)
{
    bool ans = false;
    for (auto i : word_array)
    {
        if (i == word)
        {
            return true;
        }
    }
    return false;
}

vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
{
    vector<int> ans;
    vector<pair<int, int>> name_mark;
    for (int i = 0; i < report.size(); i++)
    {
        string word = report[i];
        int positive = 0, negative = 0, final_score;
        vector<string> word_vector = wordSplit(word);
        for (auto j : word_vector)
        {
            if (checkInArray(j, positive_feedback))
                positive++;
            else if (checkInArray(j, negative_feedback))
                negative++;
        }
        final_score = abs(3 * positive - 1 * negative);
        name_mark.push_back(make_pair(student_id[i], final_score));
    }

    sort(name_mark.begin(), name_mark.end(), [&](pair<int, int> p1, pair<int, int> p2)
         {
        if(p1.second==p2.second){
            return max(p1.first,p2.first);
        }
        else if(p1.second>p2.second){
            return p1.first;
        }
        else{
            return p2.first;
        } });

    for (auto i : name_mark)
    {
        cout << i.first << ' ' << i.second << endl;
    }

    return ans;
}

int main()
{
    vector<string> arr = wordSplit("this student is studious");
    vector<string> positive = {"smart", "brilliant", "studious"};
    vector<string> negative = {"not"};
    vector<string> report = {"this student is not studious", "the student is smart"};
    vector<int> student = {1, 2};
    topStudents(positive, negative, report, student, 2);
    return 0;
}