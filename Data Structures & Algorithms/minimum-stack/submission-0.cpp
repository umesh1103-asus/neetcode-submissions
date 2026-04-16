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
            minStk.push(min(top,val));
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();

    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
