#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int length = n.size();
        set<string> candidates;

        // Edge cases
        if (n == "1")
            return "0";

        // Create the prefix
        string prefix = n.substr(0, (length + 1) / 2);
        long long prefixNumber = stoll(prefix);

        // Generate candidates
        for (long long i : {-1, 0, 1})
        {
            string newPrefix = to_string(prefixNumber + i);
            string candidate;
            if (length % 2 == 0)
            {
                candidate = newPrefix + string(newPrefix.rbegin(), newPrefix.rend());
            }
            else
            {
                candidate = newPrefix + string(newPrefix.rbegin() + 1, newPrefix.rend());
            }
            candidates.insert(candidate);
        }

        // Edge cases for smallest and largest palindromes
        candidates.insert(to_string(static_cast<long long>(pow(10, length - 1)) - 1));
        candidates.insert(to_string(static_cast<long long>(pow(10, length)) + 1));

        // Remove the original number from candidates
        candidates.erase(n);

        // Find the closest palindrome
        string closestPalindrome;
        long long minDifference = LLONG_MAX;
        long long num = stoll(n);
        for (const string &candidate : candidates)
        {
            long long candidateNum = stoll(candidate);
            long long difference = abs(candidateNum - num);
            if (difference < minDifference || (difference == minDifference && candidateNum < stoll(closestPalindrome)))
            {
                minDifference = difference;
                closestPalindrome = candidate;
            }
        }

        return closestPalindrome;
    }
};

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int len = n.length();
        if (len == 1)
        {
            return to_string(stoi(n) - 1);
        }
        vector<long long> candidates;

        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i)
        {
            string p = to_string(prefix + i);
            string candidate = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.push_back(stoll(candidate));
        }

        long long num = stoll(n);
        long long closest = -1;

        for (long long cand : candidates)
        {
            if (cand == num)
                continue;
            if (closest == -1 ||
                abs(cand - num) < abs(closest - num) ||
                (abs(cand - num) == abs(closest - num) && cand < closest))
            {
                closest = cand;
            }
        }

        return to_string(closest);
    }
};

int main()
{

    return 0;
}