class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mp;

        bool allNegative = true;
        int maxVal = INT_MIN;

        for (int n : nums) {
            if (n >= 0) allNegative = false;
            if (n > maxVal) maxVal = n;
        }
        if (allNegative) return maxVal;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int sum=0;
        for(auto &a:mp){
            if(a.first>0)            sum+=a.first;
        }
        return sum;
    }
};