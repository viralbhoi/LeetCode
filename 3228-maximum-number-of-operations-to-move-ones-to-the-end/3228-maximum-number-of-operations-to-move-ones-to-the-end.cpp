class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int prevOnes = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                while(i < n && s[i] == '0'){
                    i++;
                }

                ans += prevOnes;
                i--;
            }else{
                prevOnes++;
            }
        }

        return ans;
    }
};