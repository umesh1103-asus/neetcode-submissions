class Solution {
private:
    vector<vector<string>> res;
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;

        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    void creatPalindromeSubstrings(int idx, vector<string> temp, string currStr, string str){
        if(idx>=str.size()){
            if(isPalindrome(currStr) && currStr.size()>0) {
                temp.push_back(currStr);
                res.push_back(temp);
            }
            return;
        }

        if(isPalindrome(currStr) && currStr.size()>0){
            temp.push_back(currStr);
            cout << "yes ingesting: " << currStr << endl;
            string newStr = "";
            newStr.push_back(str[idx]);
            creatPalindromeSubstrings(idx+1, temp, newStr, str);
            temp.pop_back();
        }

        currStr.push_back(str[idx]);
        creatPalindromeSubstrings(idx+1, temp, currStr, str);
    }
public:
    vector<vector<string>> partition(string s) {
        creatPalindromeSubstrings(0, {}, "", s);
        return res; 
    }
};
