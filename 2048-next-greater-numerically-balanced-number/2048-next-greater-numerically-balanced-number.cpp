class Solution {
    bool balanced(int n){
        vector<int> v(10,0);
        while(n){
            int rem = n%10;
            n/=10;

            v[rem]++;

            if(v[rem] > rem){
                return false;
            }
        }

        for(int i=0;i<=9;i++){
            if(v[i] != 0 && v[i] != i){
                return false;
            }
        }

        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        int ans = n+1;

        while(!balanced(ans)){
            ans++;
        }

        return ans;
    }
};