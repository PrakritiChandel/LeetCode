class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int o=0,e=1,s=0,ans=0,mod= 1e9+7;
        for(int i:arr){
            s= (s+i%mod)%mod;
            if(s%2){ ans =(ans+e)%mod; o++;}
            else {ans = (ans+o)%mod; e++;}
            
        }
        return ans;
    }
};