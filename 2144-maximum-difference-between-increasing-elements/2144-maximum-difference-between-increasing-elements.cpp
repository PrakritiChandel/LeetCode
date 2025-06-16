class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    if (diff < (nums[j] - nums[i])) {
                        diff = nums[j] - nums[i];
                    }
                }
            }
        }

        return diff;
    }
};