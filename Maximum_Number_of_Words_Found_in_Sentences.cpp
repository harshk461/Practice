#include <bits/stdc++.h>
using namespace std;

int mostWordsFound(vector<string> &sentences)
{
    int maxNum = INT_MIN;
    for (int i = 0; i < sentences.size(); i++)
    {
        string word = sentences[i];
        int init_sum = 0;
        int len = word.length();
        int k = 0;
        for (int j = 0; j <= len; j++)
        {
            if (word[j] == ' ' || word[j] == '\0')
            {
                // k += 2;
                init_sum++;
            }
            // else
            // {
            //     k++;
            // }
        }
        cout << init_sum << endl;

        if (init_sum > maxNum)
        {
            maxNum = init_sum;
        }
    }
    return maxNum;
}
int main()
{
    vector<string> arr;
    arr.push_back("alice and bob love leetcode");
    arr.push_back("i think so too");
    arr.push_back("this is great thanks very much");
    cout << mostWordsFound(arr);
    return 0;
}