class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        if(n<2) return 0;

        int res = 0;
        int rMax = prices[n-1];

        for(int i=n-2;i>=0;i--){
            res = max(res, rMax-prices[i]);
            rMax = max(rMax, prices[i]);
        }

        return res;
    }
};
