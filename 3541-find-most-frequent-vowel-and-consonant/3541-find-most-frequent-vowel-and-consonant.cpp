class Solution {
public:
    int maxFreqSum(string s) {

        map<char,int> freq;

        for(char it : s){
            freq[it]++;
        }

        int vow=0,con = 0;

        for(auto it:freq){
            char ch = it.first;

            if(ch=='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                vow = max (vow,it.second);
            }else{
                con = max(con,it.second);
            }
        }

        return vow + con;
    }
};