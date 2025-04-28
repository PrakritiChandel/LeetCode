class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt = 0;
        int n = nums.size();
        int l = 0, r = 0;
        int len = 0;
        long long sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l) + 1;
            r++;
        }
        return cnt;
    }
};