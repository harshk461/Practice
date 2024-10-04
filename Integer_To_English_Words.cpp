#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, string> units = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"}};

    unordered_map<int, string> tens = {
        {2, "Twenty"},
        {3, "Thirty"},
        {4, "Forty"},
        {5, "Fifty"},
        {6, "Sixty"},
        {7, "Seventy"},
        {8, "Eighty"},
        {9, "Ninety"}};

    string trim(const string &str)
    {
        auto start = str.begin();
        while (start != str.end() && isspace(*start))
        {
            start++;
        }

        auto end = str.end();
        do
        {
            end--;
        } while (distance(start, end) > 0 && isspace(*end));

        return string(start, end + 1);
    }

    string getHundred(int num)
    {
        string str = "";
        if (num >= 100)
        {
            int n = num / 100;
            str += units[n] + " Hundred";
            num %= 100;
        }

        if (num >= 20)
        {
            int n = num / 10;
            str += " " + tens[n];
            num %= 10;
        }

        if (num > 0)
        {
            str += " " + units[num];
        }

        return trim(str);
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        vector<string> words;
        unordered_map<int, string> block_to_word = {
            {1, ""},
            {2, " Thousand"},
            {3, " Million"},
            {4, " Billion"}};

        string word = to_string(num);
        int n = word.length();
        int num_of_blocks = n / 3;
        int rem_chars = n % 3;
        int i = n - 1;
        for (int i = rem_chars; i < n; i += 3)
        {
            string temp(word.begin() + i, word.begin() + i + 3);
            // cout<<temp<<" ";
            words.push_back(temp);
        }
        reverse(words.begin(), words.end());

        if (rem_chars > 0)
        {
            string temp(word.begin(), word.begin() + rem_chars);
            // cout<<temp<<" ";
            words.push_back(temp);
        }
        reverse(words.begin(), words.end());

        for (auto it : words)
            cout << it << " ";

        string ans = "";
        int block_num = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            int curr_num = stoi(words[i]);
            // cout<<curr_num<<" ";
            string curr_ans = getHundred(curr_num);
            if (curr_ans.length() > 0)
                ans += curr_ans + block_to_word[block_num] + " ";
            block_num--;
        }

        return trim(ans);
    }
};

class Solution
{
public:
    unordered_map<int, string> un = {
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
    string numberToWords(int num)
    {
        if (!num)
            return "Zero";
        vector<string> v = {"", "Thousand", "Million", "Billion"};
        string ans = "";
        int count = 0;
        while (num)
        {
            if (num % 1000)
                ans = v[count] + " " + ans;
            count++;
            if (num % 100 > 19)
            {
                if (num % 10)
                    ans = un[num % 10] + " " + ans;
                num /= 10;
                num *= 10;
                ans = un[num % 100] + " " + ans;
            }
            else
            {
                if (num % 100)
                    ans = un[num % 100] + " " + ans;
            }
            num /= 100;
            if (num % 10)
            {
                ans = un[num % 10] + " Hundred " + ans;
            }
            num /= 10;
        }
        while (ans.size() && ans.back() == ' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{

    return 0;
}