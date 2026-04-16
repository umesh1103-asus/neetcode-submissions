class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = size(numbers) - 1;

        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum>target){
                j--;
                continue;
            }
            if(sum<target){
                i++;
                continue;
            }
            vector<int> res = {i+1,j+1};
            return res;
        }
    }
};
