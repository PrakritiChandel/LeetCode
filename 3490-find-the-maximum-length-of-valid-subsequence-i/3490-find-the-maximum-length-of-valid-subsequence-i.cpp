class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        bool bit = nums[0] % 2;
        int odd = 0;
        int even = 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == !bit) {
                ans++;
                bit = nums[i] % 2;
            }
            if (nums[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return max(ans,max(even,odd));
    }
};