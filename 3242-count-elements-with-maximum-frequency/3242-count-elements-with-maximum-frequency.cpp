class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums){
            mp[i]++;
        }

        int max=-1;
    
        for(auto const &it:mp){
            if(max<it.second){
                max=it.second;
            }
        }

        int cnt=0;
        for(auto const &it:mp){
            if(it.second==max){
                cnt+=max;
            }
        }

        return cnt;
    }
};