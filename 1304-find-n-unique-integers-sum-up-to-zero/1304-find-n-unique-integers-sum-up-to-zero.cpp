class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);

        int k = n/2;
        int idx = 0;
        for(int i = -k;i<=k;i++){
            if(n%2==0 && i == 0){
                continue;
            }
            ans[idx++] = i;
        }
        return ans;
    }
};