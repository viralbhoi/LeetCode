class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};

        vector<char> v;

        for(auto c : s){
            if(vowels.count(c)){
                v.push_back(c);
            }
        }

        sort(v.begin(),v.end());

        string temp = s;
        int idx = 0;

        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i])){
                temp[i] = v[idx++];
            }
        }

        return temp;
    }
};