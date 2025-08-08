class Solution {
    double dp[201][201];
public:
    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        else if (a > 0 && b <= 0) return 0;
        else if (a <= 0 && b > 0) return 1;
        else if (dp[a][b] != -1) return dp[a][b];
        dp[a][b] = 0.25 * (dfs(a - 4, b) + (dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3)));
        return dp[a][b];
    }

    double soupServings(int n) {
        if (n >= 4450) return 1;
        std::fill(&dp[0][0], &dp[0][0] + 201 * 201, -1);
        int bound = std::ceil(static_cast<double>(n) / 25);
        return dfs(bound, bound);
    }
};