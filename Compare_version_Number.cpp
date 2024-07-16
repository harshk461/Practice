#include <iostream>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> ver1;
        vector<int> ver2;
        int i, j;
        for (i = 0; i < version1.size(); i++)
        {
            string part;
            j = i;
            while (j < version1.size() && version1[j] != '.')
                part += version1[j++];

            i = j;
            ver1.push_back(stoi(part));
        }

        for (i = 0; i < version2.size(); i++)
        {
            string part;
            j = i;
            while (j < version2.size() && version2[j] != '.')
                part += version2[j++];

            i = j;
            ver2.push_back(stoi(part));
        }
        // for (auto it : ver1)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : ver2)
        //     cout << it << " ";

        i = 0;
        j = 0;

        while (i < ver1.size() && j < ver2.size())
        {
            if (ver1[i] > ver2[j])
                return 1;
            else if (ver1[i] < ver2[j])
                return -1;
            i++;
            j++;
        }

        while (i < ver1.size() && ver1[i] == 0)
            i++;
        while (j < ver2.size() && ver2[j] == 0)
            j++;

        if (i < ver1.size())
            return 1;

        if (j < ver2.size())
            return -1;

        return 0;
    }
};

int main()
{

    return 0;
}