class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=size(heights) - 1;

        int res = 0;
        while(i<j){
            int temp = min(heights[i], heights[j]) * (j-i);
            res = max(res, temp);
            if(heights[i]> heights[j]) j--;
            else i++;
        }

        return res;
    }
};
