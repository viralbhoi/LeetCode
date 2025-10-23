class Solution {
public:
    bool hasSameDigits(string s) {
        string temp="";
        int idx = 0;
        while(s.size() > 2 ){
            temp += ((s[idx] + s[idx+1]) - 2*'0' )%10;
            if(temp.size() == s.size() - 1){
                idx = 0;
                s = temp;
                temp = "";
                continue;
            }
            idx++;
        }

        return s[0] == s[1];
    }
};