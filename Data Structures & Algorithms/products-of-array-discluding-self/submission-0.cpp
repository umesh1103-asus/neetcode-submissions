class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=size(nums);
        vector<int> preProd(n, 1);
        vector<int> postProd(n, 1);
        int currPreProd=1, currPostProd=1;
        int i=0, j=n-1;
        while(i<n and j>=0){
            preProd[i] = currPreProd;
            postProd[j] = currPostProd;
            currPreProd = currPreProd*nums[i];
            currPostProd = currPostProd*nums[j];
            i++;
            j--; 
        }

        for(int i=0;i<n;i++){
            nums[i] = preProd[i]*postProd[i];
        }

        return nums;
    }
};
