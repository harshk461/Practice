#include <iostream>
#include <string>
using namespace std;

bool check(char a)
{
    char arr[5] = {'a', 'e', 'i', 'o', 'u'};
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == a)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        string str;
        cin >> str;
        int count=0;
        for (int i = 0; i < str.length(); i++)
        {
            
            if (!check(str[i]))
            {
                count++;
                if (count >= 4)
                {
                    break;
                }
            }
        }
        if (count >= 4)
        {
            cout << count << endl;
            cout << "YES" << endl;
        }
        else
        {
            cout << count << endl;
            cout << "NO" << endl;
        }
    }
    return 0;
}
