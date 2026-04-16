class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s:tokens){
            if(s=="+"){
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();

                stk.push(val2+val1);
            }
            else if(s=="-"){
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();

                stk.push(val2-val1);
            }
            else if(s=="*"){
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();

                stk.push(val2*val1);
            }
            else if(s=="/"){
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();

                stk.push(val2/val1);
            }
            else{
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};
