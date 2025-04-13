#define mod (long long)(1e9+7)

class Solution {
public:
    // Modular exponentiation: computes (a^b) % mod
    long long exp(long long a, long long b){
        if(b == 0) return 1;
        long long root = exp(a, b / 2);
        if(b % 2 == 0) return (root * root) % mod;
        return (a * ((root * root) % mod)) % mod;
    }

    int countGoodNumbers(long long n) {
        long long odind = n / 2;           // odd indices
        long long evind = n - odind;       // even indices
        return (exp(5, evind) * exp(4, odind)) % mod;
    }
};