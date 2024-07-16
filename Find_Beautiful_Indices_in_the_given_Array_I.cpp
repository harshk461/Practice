class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> a_index;
        vector<int> b_index;
        int n = s.length();

        int m = a.length();
        int l = b.length();

        if (n < m || n < l)
        {
            return {};
        }

        // storing string 'a' indices in s string
        for (int i = 0; i < n - m + 1; i++)
        {
            string t = s.substr(i, a.size());
            if (t == a)
                a_index.push_back(i);
        }

        // storing string 'b' indices in s string
        for (int i = 0; i < n - l + 1; i++)
        {
            string t = s.substr(i, b.size());
            if (t == b)
                b_index.push_back(i);
        }

        // for (auto it : a_index)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : b_index)
        //     cout << it << " ";
        // cout << endl;

        vector<int> ans;

        for (int i = 0; i < a_index.size(); i++)
        {
            for (int j = 0; j < b_index.size(); j++)
            {
                if (abs(a_index[i] - b_index[j]) <= k)
                {
                    ans.push_back(a_index[i]);
                    break;
                }
            }
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int n = s.size();
        int asize = a.size();
        int bsize = b.size();
        if (n < asize || n < bsize)
        {
            return {};
        }
        vector<int> v1;
        for (int i = 0; i < n - a.size() + 1; i++)
        {
            string s1 = s.substr(i, a.size());
            if (s1 == a)
            {
                v1.push_back(i);
            }
        }

        vector<int> v2;
        for (int i = 0; i < n - b.size() + 1; i++)
        {
            string s1 = s.substr(i, b.size());
            if (s1 == b)
            {
                v2.push_back(i);
            }
        }
        // for(auto x:v1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        //  for(auto x:v2){
        //     cout<<x<<" ";
        // }

        vector<int> ans;
        for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
            {
                int diff = abs(v1[i] - v2[j]);
                if (diff <= k)
                {
                    ans.push_back(v1[i]);
                    break;
                }
            }
        }
        return ans;
    }
};