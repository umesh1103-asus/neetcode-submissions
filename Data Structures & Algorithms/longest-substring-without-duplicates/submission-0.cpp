class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = size(s);
        if(n<1) return 0;
        unordered_map<char,int> mp;
        int res = 1;
        int l = 0;
        int r = 0;

        while(r<n){
            if(mp.find(s[r])==mp.end()){
                mp[s[r]] = 1;
                r++;
            }
            else{
                res = max(res, r-l);
                while(s[l]!=s[r]){
                    mp.erase(s[l]);
                    l++;
                }
                mp.erase(s[l]);
                l++;
            }
        }

        res = max(res, r-l);
        return res;
    }
};
