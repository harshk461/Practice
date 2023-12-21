#include <bits/stdc++.h>
using namespace std;

// class FoodRatings
// {
// public:
//     // food->{cuisine,rating}
//     unordered_map<string, pair<string, int>> map;
//     FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
//     {
//         int n = foods.size();
//         for (int i = 0; i < n; i++)
//             map[foods[i]] = make_pair(cuisines[i], ratings[i]);
//     }

//     void changeRating(string food, int newRating)
//     {
//         map[food].second = newRating;
//     }

//     string highestRated(string cuisine)
//     {
//         // // vector of {food,rating} for particular cuisine
//         // vector<pair<string, int>> arr;

//         // for (auto it : map)
//         //     if (map[it.first].first == cuisine)
//         //         arr.push_back({it.first, map[it.first].second});

//         // sort(arr.begin(), arr.end(), [&](const pair<string, int> &a, const pair<string, int> &b)
//         //      {
//         // if (a.second > b.second) {
//         //     return a.second > b.second;
//         // } else if (a.second == b.second) {
//         //     return a.first < b.first;
//         // }

//         // return false; });

//         // for (auto it : arr)
//         //     cout << it.first << " " << it.second << endl;

//         // return arr[0].first;
//         pair<string, int> maxi = { "",
//                                    0 } for (auto it : map)
//         {
//             if (map[it.first].first == cuisine)
//             {
//                 if ()
//             }
//         }
//     }
// };

// class FoodRatings
// {
// public:
//     unordered_map<string, int> foodToRatingMap;
//     unordered_map<string, vector<string>> CuisineToFoodMap;
//     FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
//     {
//         int n = foods.size();
//         for (int i = 0; i < n; i++)
//         {
//             foodToRatingMap[foods[i]] = ratings[i];
//             CuisineToFoodMap[cuisines[i]].push_back(foods[i]);
//         }
//     }

//     void changeRating(string food, int newRating)
//     {
//         foodToRatingMap[food] = newRating;
//     }

//     string highestRated(string cuisine)
//     {
//         vector<string> foods = CuisineToFoodMap[cuisine];
//         vector<pair<string, int>> arr;

//         for (auto it : foods)
//             arr.push_back({it, foodToRatingMap[it]});

//         sort(arr.begin(), arr.end(), [&](const pair<string, int> &a, const pair<string, int> &b)
//              {
//         if (a.second > b.second) {
//             return a.second > b.second;
//         } else if (a.second == b.second) {
//             return a.first < b.first;
//         }

//         return false; });

//         return arr[0].first;
//     }
// };

// class FoodRatings
// {
// public:
//     // Food->{rating,cuisine}
//     map<string, pair<int, string>> foodRating;

//     // Cuisine->Map(Rating->set(Foods for that cuisine))
//     map<string, map<int, set<string>>> cuisineRating;

//     FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
//     {
//         int n = foods.size();
//         for (int i = 0; i < n; i++)
//         {
//             foodRating[foods[i]] = {ratings[i], cuisines[i]};
//             cuisineRating[cuisines[i]][ratings[i]].insert(foods[i]);
//         }
//     }

//     void changeRating(string food, int newRating)
//     {
//         auto it = foodRating[food];
//         cuisineRating[it.second][it.first].erase(food);
//         if (cuisineRating[it.second][it.first].size() == 0)
//             cuisineRating[it.second].erase(it.first);

//         cuisineRating[it.second][newRating].insert(food);
//         foodRating[food] = {newRating, it.second};
//     }

//     string highestRated(string cuisine)
//     {
//         auto it = cuisineRating[cuisine].rbegin()->second;
//         return *it.begin();
//     }
// };

class FoodRatings
{
public:
    unordered_map<string, int> food_To_Rating;
    unordered_map<string, string> food_To_Cuisine;

    // set contains element in sorted way
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            food_To_Rating[foods[i]] = ratings[i];
            food_To_Cuisine[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        auto cuisine = food_To_Cuisine[food];

        auto oldElement = cuisineFoodMap[cuisine].find({-food_To_Rating[food], food});

        cuisineFoodMap[cuisine].erase(oldElement);

        food_To_Rating[food] = newRating;

        cuisineFoodMap[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        auto ans = *cuisineFoodMap[cuisine].begin();
        return ans.second;
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisine = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> rate = {9, 12, 8, 15, 14, 9};

    FoodRatings f(foods, cuisine, rate);
    f.highestRated("korean");
    return 0;
}