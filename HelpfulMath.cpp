#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[1000];
    for (int i = 0; i < str.length(); i++)
    {
        int num = (int)str[i];
        if (isdigit(num))
        {
            arr[i] = (int)str[i];
        }
    }
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i];
    }
}