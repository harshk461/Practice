#include <iostream>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int j = word.find(ch);
        if (j != -1)
        {
            reverse(word.begin(), word.begin() + i + 1);
        }
        return word;
    }
};

int main()
{

    return 0;
}