class Solution {
private:
    bool isValid(string s){
        if(s[0]=='0') return false;
        if(stoi(s)>26) return false;
        return true;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<int> ways(n+1, 0); // 1 indexed
        if(n>=1 && s[0]=='0') return 0;
        ways[0] = ways[1]= 1;
        for(int i=2;i<=n;i++){
            string curr = "";
            curr += s[i-1];
            if(isValid(curr)) ways[i] += ways[i-1];
            cout << "curr string: " << curr;
            cout << " valid ? : " << isValid(curr) << endl;
            curr = "";
            curr += s[i-2];
            curr += s[i-1];
            if(isValid(curr)) ways[i] += ways[i-2];
            cout << "curr string: " << curr;
            cout << " valid ? : " << isValid(curr) << endl;
            if(ways[i]==0) return 0;
        }

        return ways[n];
    }
};
