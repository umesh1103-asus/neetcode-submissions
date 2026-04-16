class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sRep(26, 0);
        vector<int> tRep(26, 0);

        for (char c:s) sRep[c - 'a'] = 1+sRep[c-'a'];
        for (char c:t) tRep[c-'a'] = 1+tRep[c-'a'];

        return sRep==tRep; 
    }
};
