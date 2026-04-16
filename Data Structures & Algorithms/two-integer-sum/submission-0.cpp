class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        unordered_map<int,int> sumPair;
        for(int i=0;i<size(nums); i++){
            auto pairedNum = sumPair.find(target-nums[i]);
            if(pairedNum != sumPair.end()){
                return {pairedNum->second, i};
            }
            sumPair.insert({nums[i], i});
        }
    }
};
