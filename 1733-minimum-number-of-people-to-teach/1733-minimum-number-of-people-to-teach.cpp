class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {

        set<int> need_to_learn;
        for (auto friends : friendships) {
            int p1 = friends[0];
            int p2 = friends[1];

            bool found = false;
            for (auto lang1 : languages[p1-1]) {
                for (auto lang2 : languages[p2-1]) {
                    if (lang1 == lang2) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                need_to_learn.insert(p1);
                need_to_learn.insert(p2);
            }
        }

        map<int,set<int>> already_knows;

        for(auto p : need_to_learn){
            for(auto lang : languages[p-1]){
                already_knows[lang].insert(p);
            }
        }

        int ans = INT_MAX;

        for(int l = 1; l <= n; l++){
            int teach = need_to_learn.size() - already_knows[l].size();

            ans = min (teach, ans);
        }

        return ans;
    }
};