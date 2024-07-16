class Solution
{
public:
    string compressedString(string word)
    {
        int i = 0;
        int count = 0;
        int n = word.length();
        string ans = "";
        while (i < n)
        {
            char curr = word[i];
            while (curr == word[i])
            {
                if (count == 9)
                {
                    count = 1;
                    ans += "9";
                    ans.push_back(curr);
                    i++;
                }
                else
                {
                    count++;
                    i++;
                }
            }
            ans += to_string(count);
            ans.push_back(curr);
            count = 0;
            curr = word[i];
        }

        return ans;
    }
};