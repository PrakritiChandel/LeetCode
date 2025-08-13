class Solution {
    bool check(int n){
        if(n==1) return true;
        int rem=n%3;
        if(rem!=0){
            return false;
        }
        return check(n/3);
    }
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        return check(n);
    }
};