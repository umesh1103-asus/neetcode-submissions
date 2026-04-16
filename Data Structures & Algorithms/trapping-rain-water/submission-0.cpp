class Solution {
public:
    int trap(vector<int>& height) {
        int n = size(height);
        int maxHeight = 0;
        for(int i:height) maxHeight = max(maxHeight, i);
        int totalWater = 0;
        for(int i=1;i<=maxHeight;i++){
            int start = 0;
            int end = start + 1;
            while(end<n){
                if(height[start]<i){
                    start++;
                    end = start + 1;
                    continue;
                }
                if(height[end]<i){
                    end++;
                    continue;
                }
                totalWater += end-start-1;
                start = end;
                end++;
            }
        }

        return totalWater;
        
    }
};
