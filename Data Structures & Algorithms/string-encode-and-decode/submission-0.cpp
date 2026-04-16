class Solution {
public:

    string encode(vector<string>& strs) {
        vector<string> encodedStrings;
        string res="";
        for(string s: strs){
            string temp="";
            for(char c:s){
                temp += to_string(c-' ');
                temp.push_back('-');
            }
            encodedStrings.push_back(temp);
        }
        for(string v:encodedStrings){
            res += v + '/';
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string currString = "";
        string intString = "";
        for(char c:s){
            if(c == '-'){
                if(size(intString)>0){
                    int charVal = stoi(intString);
                    currString += charVal + ' ';
                }
                intString = "";
                continue;
            } 

            else if(c == '/'){
                res.push_back(currString);
                intString = "";
                currString = "";
                continue;
            }
            else {
                intString += c;
            }
        }

        return res;
    }
};
