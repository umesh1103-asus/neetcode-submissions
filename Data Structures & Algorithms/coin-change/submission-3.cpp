class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        const int INF = 1e8;
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        for (int i = 0; i < n; i++) dp[i][0] = 0;

        for (int x = 1; x <= amount; x++) {
            if (x % coins[0] == 0) dp[0][x] = x / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int x = 1; x <= amount; x++) {
                dp[i][x] = dp[i - 1][x];
                if (x >= coins[i] && dp[i][x - coins[i]] != INF) {
                    dp[i][x] = min(dp[i][x], 1 + dp[i][x - coins[i]]);
                }
            }
        }

        return dp[n - 1][amount] == INF ? -1 : dp[n - 1][amount];
    }
};
