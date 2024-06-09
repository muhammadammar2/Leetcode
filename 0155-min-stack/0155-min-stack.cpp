class MinStack {
    private : 
    stack <int> Stack;
    stack <int> minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        Stack.push(val);
        minStack.push(min(val , minStack.top()));
    }
    
    void pop() {
        Stack.pop();
        minStack.pop();
    }
    
    int top() {
      return Stack.top();
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