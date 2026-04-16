class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = size(temperatures);
        vector<int> res(n,0);
        stack<pair<int, int>> st;
        if(n<2) return res;

        st.push(pair<int,int>(n-1,temperatures.back()));
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().second<=temperatures[i]) st.pop();
            if(st.empty()){
                st.push(pair<int,int>(i,temperatures[i]));
                continue;
            }
            res[i] = st.top().first - i;
            st.push(pair<int,int>(i, temperatures[i]));
        }

        return res;
    }
};
