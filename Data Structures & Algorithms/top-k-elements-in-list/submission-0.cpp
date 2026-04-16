class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<vector<int>> freq;
        vector<int> res;
        sort(nums.begin(), nums.end());
        int i=0;
        int j=0;

        while(i<size(nums)){
            while(j<size(nums) and nums[i]==nums[j]) j++;
            vector<int> temp = {j-i, nums[i]};
            freq.push(temp);
            i=j; 
        }

        while(!freq.empty()){
            vector<int> v = freq.top();
            res.push_back(v[1]);
            freq.pop();
            k--;
            if(k==0) return res;
        }
        return res;
    }
};
