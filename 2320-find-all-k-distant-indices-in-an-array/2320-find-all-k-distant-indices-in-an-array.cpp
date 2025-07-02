class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size();

        vector<int> indices;
        set<int>s;

        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (key == nums[i]) {
                ind = i;
                for (int j = 0; j < n; j++) {
                    if ((abs(j - i) <= k)) {
                        s.insert(j);
                    }
                }
            }
        }

        for(int i:s){
            indices.push_back(i);
        }

        return indices;
    }
};