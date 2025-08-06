class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0;
        int j = 0;

        unordered_map<int, int> mp;
        int result = 0;

        while(j < n){
            while(mp.find(fruits[j]) == mp.end() && mp.size() >= 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }

            mp[fruits[j]]++;
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};