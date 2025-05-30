class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans = image;
        for (int i = 0; i < image.size(); i++) {
            reverse(ans[i].begin(), ans[i].end());
            for (int j = 0; j < image.size(); j++) {
                ans[i][j] = (ans[i][j] == 0) ? 1 : 0;
            }
        }
        return ans;
    }
};