class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> maxProd(2, vector<int>(n));

        int ans = INT_MIN;
        maxProd[0][0] = maxProd[1][0] = nums[0];
        ans = max(ans, maxProd[0][0]);
        for(int i=1;i<n;i++){
            maxProd[0][i] = max(max(nums[i]*maxProd[1][i-1], nums[i]*maxProd[0][i-1]), nums[i]);
            maxProd[1][i] = min(min(nums[i]*maxProd[0][i-1], nums[i]*maxProd[1][i-1]), nums[i]);
            ans = max(ans, maxProd[0][i]);
            ans = max(ans, maxProd[1][i]);
        }

        return ans;
    }
};
