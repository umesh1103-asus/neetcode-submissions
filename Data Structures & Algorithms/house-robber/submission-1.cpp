class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<vector<int>> robMoney(n+1, vector<int>(2,0));
        for(int i=1;i<=n;i++){
            robMoney[i][0] = max(robMoney[i-1][0], robMoney[i-1][1]);
            robMoney[i][1] = nums[i-1] + robMoney[i-1][0];
        }

        return max(robMoney[n][0], robMoney[n][1]);
    }
};
