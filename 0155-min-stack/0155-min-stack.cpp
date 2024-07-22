class MinStack {
private: 
    stack <int> MS;
    stack <int> ms;
public:
    MinStack() {
      ms.push(INT_MAX);  
    }
    
    void push(int val) {
        MS.push(val);
        ms.push(min(val , ms.top()));
    }
    
    void pop() {
        MS.pop();
        ms.pop();
    }
    
    int top() {
        return MS.top();
    }
    
    int getMin() {
        return ms.top();
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