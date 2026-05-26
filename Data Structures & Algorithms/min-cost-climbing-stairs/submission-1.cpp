class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==0 || n==1) return 0;
        vector<int> stairCost(n, 1e8);
        stairCost[0] = cost[0];
        stairCost[1] = cost[1];

        for(int i=2;i<n;i++) stairCost[i] = cost[i] + min(stairCost[i-1], stairCost[i-2]);
        return min(stairCost[n-2], stairCost[n-1]);
    }
};
