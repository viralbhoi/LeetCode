class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        int idx = 0;
        int cur = 1;
        while(idx < target.size()){
            ans.push_back("Push");
            if(target[idx] != cur){
                ans.push_back("Pop");
                idx--;
            }

            cur++;
            idx++;
        }

        return ans;
    }
};