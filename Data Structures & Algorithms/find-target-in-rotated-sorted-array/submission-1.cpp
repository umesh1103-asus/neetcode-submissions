class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<nums[r]) r = mid;
            else l = mid+1;
        }

        cout << "min: " << l << endl;

        if(nums[l]==target) return l;

        int start = 0, end = l-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end = mid-1;
            else start = mid+1;
        }

        start = l+1,end=nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end = mid-1;
            else start = mid+1;
        }

        return -1;
    }
};
