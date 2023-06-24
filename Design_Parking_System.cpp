#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
    unordered_map<string, int> map;
    ParkingSystem(int big, int medium, int small)
    {
        while (big > 0)
        {
            map["big"]++;
            big--;
        }
        while (medium > 0)
        {
            map["medium"]++;
            medium--;
        }
        while (small > 0)
        {
            map["small"]++;
            small--;
        }
    }

    bool addCar(int carType)
    {
        bool ans=false;
        if (carType == 1)
        {
            if (map["big"] > 0)
            {
                map["big"]--;
                ans=true;   
            }
        }
        else if (carType == 2)
        {
            if (map["medium"] > 0)
            {
                map["medium"]--;
                ans=true;
            }
        }

        else if (carType == 3)
        {
            if (map["small"] > 0)
            {
                map["small"]--;
                ans=true;
            }
        }
        return ans;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main()
{

    return 0;
}