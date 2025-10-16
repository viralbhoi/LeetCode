class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();

        vector<int> pre(n,0);
        pre[0] = s[0] - 'a';

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + (s[i] - 'a');
        }

        int sum = pre[n-1];
        for(int i=0;i<n-1;i++){
            if(pre[i] == sum - pre[i]){
                return true;
            }
        }

        return false;
    }
};