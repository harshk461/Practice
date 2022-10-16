#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string str;
        cin >> n;
        cin >> str;
        int s = 0;
        int e = str.length() - 1;
        if (str.length() % 2 != 0)
        {
            e--;
        }
        int i = 0;
        while (i < e)
        {
            swap(str[i], str[i + 1]);
            i += 2;
        }

        for (int i = 0; i < str.length(); i++)
        {
            str[i]='a'+(26-(str[i]-'a'))-1;
	        
        }
        cout << str << endl;
    }
    return 0;
}
