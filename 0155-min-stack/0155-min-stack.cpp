class MinStack {
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }

    void push(int val) {
        
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        int popped = mainStack.top();
        mainStack.pop();
        
        if (popped == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }

};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */