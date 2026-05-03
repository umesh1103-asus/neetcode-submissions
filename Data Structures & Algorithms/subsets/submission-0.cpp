class Solution {
private:
    vector<vector<int>> res;
    void createSubset(vector<int>& nums, vector<int> subSet, int index){
        if(index >= nums.size()) {
            res.push_back(subSet);
            return;
        }

        createSubset(nums, subSet, index+1);
        subSet.push_back(nums[index]);
        createSubset(nums, subSet, index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        createSubset(nums, {}, 0);
        return res;
    }
};
