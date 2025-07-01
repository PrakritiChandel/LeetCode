class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: Pair values with their indices
        vector<pair<int, int>> val_idx;
        for (int i = 0; i < nums.size(); ++i) {
            val_idx.push_back({nums[i], i});
        }

        // Step 2: Sort by value descending
        sort(val_idx.begin(), val_idx.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        // Step 3: Take top k elements
        vector<pair<int, int>> top_k(val_idx.begin(), val_idx.begin() + k);

        // Step 4: Sort by original index to preserve order
        sort(top_k.begin(), top_k.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        // Step 5: Extract result
        vector<int> result;
        for (auto& p : top_k) {
            result.push_back(p.first);
        }

        return result;
    }
};
