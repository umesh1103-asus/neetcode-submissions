class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<vector<int>> robMoney(n, vector<int>(2, 0));
        int ans = 0;
        robMoney[0][1] = nums[0];

        for (int i = 1; i < n - 1; i++) {
            robMoney[i][0] = max(robMoney[i - 1][0], robMoney[i - 1][1]);
            robMoney[i][1] = nums[i] + robMoney[i - 1][0];
        }

        ans = max(robMoney[n - 2][0], robMoney[n - 2][1]);

        // Case 2: use houses [1 .. n-1]
        robMoney.assign(n, vector<int>(2, 0));
        robMoney[1][0] = 0;
        robMoney[1][1] = nums[1];

        for (int i = 2; i < n; i++) {
            robMoney[i][0] = max(robMoney[i - 1][0], robMoney[i - 1][1]);
            robMoney[i][1] = nums[i] + robMoney[i - 1][0];
        }

        ans = max(ans, max(robMoney[n - 1][0], robMoney[n - 1][1]));
        return ans;
    }
};
