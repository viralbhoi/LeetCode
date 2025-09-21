class MovieRentingSystem {
    map<int, set<pair<int, int>>> available;
    set<vector<int>> rented;
    map<pair<int, int>, int> price;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e : entries){
            available[e[1]].insert({e[2],e[0]});
            price[{e[0],e[1]}] = e[2];
        }
    }

    vector<int> search(int movie) {
        vector<int> res;

        if(available.count(movie)){
            for(auto &p : available[movie]){
                res.push_back(p.second);
                if(res.size() == 5)
                    break;
            }
        }

        return res;
    }

    void rent(int shop, int movie) {
        pair<int,int> p = {shop, movie};
        int pr = price[p];
        available[movie].erase({pr, shop});
        rented.insert({pr, shop, movie});
    }

    void drop(int shop, int movie) {
        pair<int,int> p = {shop, movie};
        int pr = price[p];
        rented.erase({pr, shop, movie});
        available[movie].insert({pr, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;

        for(auto &t : rented){
            result.push_back({t[1],t[2]});

            if(result.size() == 5){
                break;
            }
        }

        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */