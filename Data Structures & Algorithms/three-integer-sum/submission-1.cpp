class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = size(nums);
        sort(nums.begin(), nums.end());
        set<vector<int>> sol;
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            int target = 0-nums[i];

            while(j<k){
                int sum = nums[j] + nums[k];
                if(sum<target){
                    j++;
                    continue;
                }

                if(sum>target){
                    k--;
                    continue;
                }

                vector<int> temp = {nums[i],nums[j],nums[k]};
                sol.insert(temp);
                j++;
                k--;
            }
        }

        for(auto v:sol) res.push_back(v);
        return res;
    }
};
