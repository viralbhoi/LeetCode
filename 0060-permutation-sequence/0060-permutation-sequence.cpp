class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> permutation;
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        getAns(permutation,nums,0);

        sort(permutation.begin(),permutation.end());

        return permutation[k-1];
    }

    void getAns(vector<string> &ans,vector<int> &a,int idx){
        if(idx == a.size()){
            string temp="";
            for(auto e:a){
                temp+=e+'0';
            }
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<a.size();i++){
            swap(a[idx],a[i]);
            getAns(ans,a,idx+1);
            swap(a[idx],a[i]);
        }
    }
};