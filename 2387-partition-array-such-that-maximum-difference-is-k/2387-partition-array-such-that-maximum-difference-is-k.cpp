class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, c = 0;
        sort(nums.begin(), nums.end());
        while(i < n && j < n)
        {
            if(nums[j] - nums[i] <= k)
            {
                j++;
            }
            else
            {
                i = j;
                c++;
            }
        }
        return c+1;
    }
};