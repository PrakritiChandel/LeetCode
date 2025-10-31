class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> arr;
        for(int num:nums){
            mp[num]++;
        }
        for(auto &m:mp){
            if(m.second==2){
                arr.push_back(m.first);
            }
        }
        return arr;
    }
};