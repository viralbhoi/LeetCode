class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%3!=0){
            return false;
        }
        if(n%10!=1 && n%10!=3 && n%10!=7 && n%10!=9){
            return false;
        }
        return isPowerOfThree(n/3);
    }
};