class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_map<int, vector<int>> index_of_lowercase;
        unordered_map<int, int> first_occurence_of_uppercase;

        for (auto it : word)
        {
            if (it >= 'A' && it <= 'Z')
                first_occurence_of_uppercase[it] = -1;
        }

        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                index_of_lowercase[word[i]].push_back(i);
            }
            else if (word[i] >= 'A' && word[i] <= 'Z' && first_occurence_of_uppercase[word[i]] == -1)
            {
                first_occurence_of_uppercase[word[i]] = i;
            }
        }

        // for (auto it : index_of_lowercase)
        // {
        //     cout << it.first << "->";
        //     for (auto i : it.second)
        //         cout << i << " ";
        //     cout << endl;
        // }

        // for (auto it : first_occurence_of_uppercase)
        //     cout << it.first << " " << it.second << endl;

        int ans = 0;
        for (auto it : index_of_lowercase)
        {
            char lower = it.first;
            vector<int> lower_indexes = it.second;
            char upper = lower - 'a' + 65;
            if (first_occurence_of_uppercase.find(upper) != first_occurence_of_uppercase.end())
            {
                int upper_index = first_occurence_of_uppercase[upper];
                bool flag = false;
                for (auto idx : lower_indexes)
                {
                    if (idx > upper_index)
                        flag = true;
                }

                if (!flag)
                    ans++;
            }
        }

        return ans;
    }
};