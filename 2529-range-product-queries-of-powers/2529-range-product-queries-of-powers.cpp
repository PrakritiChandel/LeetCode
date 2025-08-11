class Solution {
private:
    static constexpr int MODULO = 1e9+7;
    long long fastPow(long long base, long long exp) {
        long long result = 1;
        base %= MODULO;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MODULO;
            }
            base = (base * base) % MODULO;
            exp >>= 1;
        }
        return result;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int current = 0;
        vector<int> powers;
        while(n){
            if(n&1)powers.push_back(current);
            n >>= 1;
            current += 1;
        }
        vector<int> ans;
        vector<long long> prefix(powers.size());
        
        for(int i=0; i<powers.size(); i++){
            if(i==0) prefix[i] = powers[i];
            else prefix[i] = powers[i] + prefix[i-1];
        }
        for(auto q: queries){
            int start = q[0], end = q[1];
            long long prod = prefix[end];
            if(start>0) prod -= prefix[start-1];
            long long result = fastPow(2, prod);
            ans.push_back(result);
        }
        return ans;
    }
};