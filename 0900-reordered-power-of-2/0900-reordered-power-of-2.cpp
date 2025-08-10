class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Convert the input number to a string and sort its digits
        string s = to_string(n);
        sort(s.begin(), s.end());

        // Iterate through all powers of 2 within the constraints
        for (int i = 0; i < 30; ++i) {
            long long powerOf2 = 1LL << i; // Calculate 2^i

            // Convert the power of 2 to a string and sort its digits
            string s2 = to_string(powerOf2);
            sort(s2.begin(), s2.end());

            // Compare the sorted strings
            if (s == s2) {
                return true;
            }
        }
        
        return false;
    }
};