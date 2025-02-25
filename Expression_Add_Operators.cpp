#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    void generate(int idx, int possible_operators, string &current, vector<string> &combs, string &ops)
    {
        if (idx == possible_operators)
        {
            combs.push_back(current);
            return;
        }

        for (char op : ops)
        {
            current.push_back(op);
            generate(idx + 1, possible_operators, current, combs, ops);
            current.pop_back();
        }
    }

    string convert(string number, string ops)
    {
        int i = 0;

        string ans = "";
        while (i < number.length() - 1)
        {
            ans += number[i] + ops[i];
        }
        ans += number[number.length() - 1];

        return ans;
    }

    int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*')
            return 2;
        return 0;
    }

    void process(stack<int> &nums, stack<char> &ops)
    {
        if (nums.size() < 2 || ops.empty())
            return;

        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();

        int result = 0;
        if (op == '+')
            result = a + b;
        else if (op == '-')
            result = a - b;
        else if (op == '*')
            result = a * b;

        nums.push(result);
    }

    int evaluate(string s)
    {
        stack<int> nums;
        stack<char> ops;
        int n = s.length();
        int i = 0;

        while (i < n)
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                while (!ops.empty() && precedence(ops.top()) >= precedence(s[i]))
                {
                    process(nums, ops);
                }
                ops.push(s[i]);
                i++;
            }
            else
            {
                i++;
            }
        }

        while (!ops.empty())
        {
            process(nums, ops);
        }

        return nums.top();
    }

    vector<string> brute(string num, int target)
    {
        int possible_operators = num.length() - 1;
        string ops = "*+-";
        vector<string> combs;
        string curr = "";
        generate(0, possible_operators, curr, combs, ops);

        vector<string> ans;

        for (auto it : combs)
        {
            string temp = convert(num, it);
            int evaluated_number = evaluate(temp);
            if (evaluated_number == target)
                ans.push_back(temp);
        }

        return ans;
    }

public:
    vector<string> addOperators(string num, int target)
    {
        return brute(num, target);
    }
};

int main()
{

    return 0;
}