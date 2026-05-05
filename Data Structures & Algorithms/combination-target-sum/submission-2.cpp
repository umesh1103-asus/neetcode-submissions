class Solution {
private:
    set<vector<int>> res;
    void findTargetSum(int currSum, int idx, int target, vector<int>& nums, vector<int> subSet){
        if(idx>=nums.size() || currSum>target) return;
        if(currSum == target) res.insert(subSet);
        findTargetSum(currSum, idx+1, target, nums, subSet);
        subSet.push_back(nums[idx]);
        findTargetSum(currSum+nums[idx], idx, target, nums, subSet);
        findTargetSum(currSum+nums[idx], idx+1, target, nums, subSet);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        findTargetSum(0, 0, target, nums, {});
        vector<vector<int>> uniqueSet;
        for(auto v:res) uniqueSet.push_back(v);
        return uniqueSet;
    }
};
