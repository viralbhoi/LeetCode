class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = nums[i] + pre[i-1];
        }

        int sum = pre[n-1];

        int cnt = 0;

        for(int i=0;i<n-1;i++){
            if(abs(pre[i] - (sum-pre[i])) %2 ==0){
            cnt++;
            }
            }
        return cnt;
    }
};