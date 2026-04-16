class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if(nums[0]<=nums[n-1]) return nums[0];
        return recFind(0, n-1, nums).second;
    }

    pair<bool,int> recFind(int start, int end, vector<int> &nums){
        cout << "starting rec with " << start << " " << end << endl; 
        int n = nums.size();
        if(start>end) return {false, -1};

        int mid = start + (end-start+1)/2;
        cout << mid << endl;
        if(mid == 0){
            if(nums[mid]<nums[mid+1]) return {true,nums[mid]};
            else return recFind(mid+1, end, nums);
        }
        if(mid==n-1){
            if(nums[mid]<nums[mid-1]) return {true,nums[mid]};
            else return recFind(start, mid-1, nums);
        }

        if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) return {true, nums[mid]};
        cout << "before call 1: " << start << " " << mid-1 << endl;
        pair<bool, int> res1 = recFind(start, mid-1, nums);
        cout << "before call 2: " << mid+1 << " " << end << endl;
        pair<bool, int> res2 = recFind(mid+1, end, nums);
        if(res1.first && res2.first){
            if(res1.second<res2.second) return res1;
            return res2;
        }
        if(res1.first) return res1;
        return res2;
    }
};
