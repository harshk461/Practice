#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (s1.find('?') != string::npos)
        {
            unordered_map<char, int> map;
            map['A'] = 0;
            map['B'] = 0;
            map['C'] = 0;
            for (auto it : s1)
                map[it]++;

            if (map['A'] == 0)
                cout << 'A' << endl;
            if (map['B'] == 0)
                cout << 'B' << endl;
            if (map['C'] == 0)
                cout << 'C' << endl;
        }

        else if (s2.find('?') != string::npos)
        {
            unordered_map<char, int> map;
            map['A'] = 0;
            map['B'] = 0;
            map['C'] = 0;
            for (auto it : s2)
                map[it]++;

            if (map['A'] == 0)
                cout << 'A' << endl;
            if (map['B'] == 0)
                cout << 'B' << endl;
            if (map['C'] == 0)
                cout << 'C' << endl;
        }
        else if (s3.find('?') != string::npos)
        {
            unordered_map<char, int> map;
            map['A'] = 0;
            map['B'] = 0;
            map['C'] = 0;
            for (auto it : s3)
                map[it]++;

            if (map['A'] == 0)
                cout << 'A' << endl;
            if (map['B'] == 0)
                cout << 'B' << endl;
            if (map['C'] == 0)
                cout << 'C' << endl;
        }
    }
    return 0;
}