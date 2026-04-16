class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(size(nums)<1) return false;
        unordered_map<int,int> isPresent;
        for(int v:nums){
            if(isPresent.find(v) != isPresent.end()) return true;
            isPresent.insert({v, 1});
        }
        return false;
    }
};