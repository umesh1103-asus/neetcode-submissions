class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        int start = 0, end = n-1;

        while(start<=end){
            int mid = start + (end-start+1)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }

        return -1;
    }
};
