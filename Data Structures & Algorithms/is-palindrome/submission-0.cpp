class Solution {
public:
    bool isPalindrome(string s) {
        int len = size(s);
        if(len<2) return true;

        string alphaNum="";
        for(char c:s) {
            int smallCap = c-'a';
            int cap = c-'A';
            int num = c-'0';

            if(smallCap>=0 and smallCap<26){
                alphaNum.push_back(c);
                continue;
            }
            if(num>=0 and num<10){
                alphaNum.push_back(c);
                continue;
            }
            if(cap>=0 and cap<26){
                alphaNum.push_back(cap+'a');
                continue;
            }
        }

        int i=0;
        int j=size(alphaNum)-1;

        while(i<j){
            if(alphaNum[i]!=alphaNum[j]) return false;
            i++;
            j--;
        }

        return true;
        
    }
};
