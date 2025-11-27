class Solution {

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& n1, const int& n2) {
            string a = to_string(n1);
            string b = to_string(n2);

            return a + b > b + a;
        });

        bool allZero = true;

        string ans = "";

        for (auto &num : nums) {
            if(num != 0){
                allZero = false;
            }
            ans += to_string(num);
        }

        return allZero ? "0" : ans;
    }
};