class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ori_k = k;
        bool found = false;

        while (1) {
            bool check = true;
            
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == k) {
                    check = false;
                    break;
                }
            }

            if (check) {
                break;
            }
            k += ori_k;
        }

        return k;
    }
};