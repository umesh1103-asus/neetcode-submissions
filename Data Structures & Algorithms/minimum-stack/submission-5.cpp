class MinStack {
private:
    std::stack<int> minStk;
    std::stack<int> stk;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty()) minStk.push(val);
        else{
            int top = minStk.top();
            if(val<=top) minStk.push(val);
        }
    }
    
    void pop() {
        int top = stk.top();
        stk.pop();
        if(top == minStk.top()) minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
