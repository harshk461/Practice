#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 0;
    int time;
    cin >> time;

    for (int i = 0; i < time; i++)
    {
        string data;
        cin >> data;
        if (data[1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x << endl;
    return 0;
}