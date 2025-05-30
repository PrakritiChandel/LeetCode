class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> set(n + 1, false);  // Initialize all to false
        for (int num : nums) {
            if (set[num]) {
                return num;
            }
            set[num] = true;
        }
        return -1;
    }
};