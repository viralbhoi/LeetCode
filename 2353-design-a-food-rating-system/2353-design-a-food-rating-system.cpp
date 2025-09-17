class FoodRatings {
    map<string, set<pair<int, string>>> mp;
    map<string, string> foodToCuisine;
    map<string, int> foodToRate;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();

        for (int i = 0; i < n; i++) {
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRate[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        mp[cuisine].erase({-foodToRate[food], food});
        mp[cuisine].insert({-newRating, food});
        foodToRate[food] = newRating;
    }

    string highestRated(string cuisine) { return mp[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */