#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    unordered_map<string, string> foodToCuisine; // food -> cuisine
    unordered_map<string, int> foodToRating;     // food -> rating
    unordered_map<string, set<pair<int, string>>> cuisineMap; // cuisine -> ordered foods

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;

            cuisineMap[cuisine].insert({-rating, food}); // store as negative rating for max-heap behavior
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        // Remove old entry
        cuisineMap[cuisine].erase({-oldRating, food});

        // Insert new entry
        cuisineMap[cuisine].insert({-newRating, food});

        // Update food rating
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        // The first element in set is the highest rating (since stored as -rating)
        return cuisineMap[cuisine].begin()->second;
    }
};
