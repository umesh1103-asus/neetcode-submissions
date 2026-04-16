class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = size(temperatures);
        vector<int> res(n,0);
        if(n<2) return res;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[j]>temperatures[i]){
                    res[i] = j-i;
                    break;
                }
            }
        }

        return res;
    }
};
