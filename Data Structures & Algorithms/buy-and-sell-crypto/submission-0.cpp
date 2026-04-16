class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        if(n<2) return 0;

        int res = 0;
        vector<int> rightMax(n, -1);
        int rMax=prices[n-1];
        
        for(int i=n-1;i>=0;i--){
            rightMax[i] = rMax;
            rMax = max(rMax, prices[i]);
        }

        for(int i=0;i<n; i++) res = max(res, rightMax[i]-prices[i]);
        return res;
    }
};
