class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> anagramBucket;
        for(string s:strs){
            vector<int> rep(26, 0);
            for(char c:s) rep[c-'a']++;
            anagramBucket[rep].push_back(s);
        }

        for(auto mapPointer:anagramBucket) res.push_back(mapPointer.second);
        return res;
    }
};
