class MinStack {
public:
    //basic idea is to store the diffrence of the new number and the minimum instead of original number
    stack<long> s;
    long minVal;
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        /*
        1. if new number is larger than minimum, stores (number - minimum) to stack and 
            keep minimum unchanged. The top of stack (number - minimum) is larger than 0.
        2. If new number is smaller than minimum, stores (number - minimum) to stack and
            update minimum to new number. 
            The top of stack (number - minimum) is smaller than 0.
        */
        
        long difference = val - minVal;
        s.push(difference);
        if(difference < 0) minVal = val;
    }
    
    void pop() {
        /*
        1. if top is large than 0, it means the number to pop is larger than minimum, 
            so true top number is minimum + stack.top(), and minimum is unchanged.
        2. If top is smaller than 0, it means that the number to pop is minimum number,
            so true top number is minimum, and new minimum is minimum - stack.top();
        */
        
        long difference = s.top();
        s.pop();
        if(difference < 0) minVal -= difference;
    }
    
    int top() {
        long difference = s.top();
        if(difference > 0) return minVal + difference;
        else return minVal;
    }
    
    int getMin() {
        return minVal;
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