class Solution {
    int dp[1000][1000];
    // bottom left
    int f(int x, int y, const vector<vector<int>>&fruits, const int n) {
        if(x < y) return -1e6;
        if(x < 0 || y < 0 || x > n-1 || y > n -1) return -1e6;
        if(x == n-1 && y == n-1) return 0;

        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = fruits[x][y] + max({
            f(x + 1, y + 1, fruits, n),
            f(x - 1, y + 1, fruits, n),
            f(x, y + 1, fruits, n)
        });
    }
    // top right
    int g(int x, int y, const vector<vector<int>>&fruits, const int n) {
        if(x > y) return -1e6;
        if(x < 0 || y < 0 || x > n-1 || y > n -1) return -1e6;
        if(x == n-1 && y == n-1) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = fruits[x][y] + max({
            g(x + 1, y + 1, fruits, n),
            g(x + 1, y - 1, fruits, n),
            g(x + 1, y, fruits, n)
        });
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        memset(dp, -1, sizeof(dp));
        int c1 = 0, n = fruits.size();
        for(int i=0; i<n; i++) {
            c1 += fruits[i][i];
            fruits[i][i] = 0;
        }
        return c1 + f(n-1, 0, fruits, n) + g(0, n-1, fruits, n);
    }
};