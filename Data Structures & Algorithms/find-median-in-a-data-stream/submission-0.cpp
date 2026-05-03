class MedianFinder {
private:
    priority_queue<int> maxQue;
    priority_queue<int, vector<int>, greater<int>> minQue;
public:
    MedianFinder() {
        
    }

    void balanceQues(){
        if (this->maxQue.size() > this->minQue.size() + 1) {
            this->minQue.push(this->maxQue.top());
            this->maxQue.pop();
        } else if (this->minQue.size() > this->maxQue.size()) {
            this->maxQue.push(this->minQue.top());
            this->minQue.pop();
        }
    }
    
    void addNum(int num) {
        if (maxQue.empty() || num <= maxQue.top()) {
            maxQue.push(num);
        } else {
            minQue.push(num);
        }
        balanceQues();
    }
    
    double findMedian() {
        if (maxQue.size() > minQue.size()) {
            return maxQue.top();
        }
        return (maxQue.top() + minQue.top()) / 2.0;
    }
};
