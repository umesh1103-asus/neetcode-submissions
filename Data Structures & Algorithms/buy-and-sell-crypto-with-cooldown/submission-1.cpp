class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<int> dp(n+2, 0);
        for(int i=3;i<=n+1;i++){
            dp[i] = dp[i-1];
            for(int j=2;j<i;j++){
                if(prices[i-2]>prices[j-2]){
                    dp[i] = max(dp[i], prices[i-2]-prices[j-2] + dp[j-2]);
                }
            }
        }

        return dp[n+1];
    }
};
