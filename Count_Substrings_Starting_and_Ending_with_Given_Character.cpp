class Solution
{
public:
    long long countSubstrings(string s, char c)
    {
        long long count = 0;
        for (auto it : s)
            if (it == c)
                count++;

        // it's like checking all the possible combinations of the occurence of that charcter
        // only make combination if start<=end
        long long ans = count * (count + 1) / 2;
        return ans;
    }
};