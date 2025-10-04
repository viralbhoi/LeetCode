class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r=height.size()-1;
        
        // int leftMax=0,rightMax=0;
        int mw = 0;
        while(l<r){
            int width = r-l;
            int ht = min(height[l],height[r]);
            mw = max(mw,width*ht);
            
            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
            
        }
        
        return mw;
    }
};