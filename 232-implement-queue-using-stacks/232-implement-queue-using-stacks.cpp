class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s2.empty()) s2.push(x);
        else s1.push(x);
    }
    
    int pop() {
        int ans = s2.top();
        if(ans == -1) return -1;
        
        s2.pop();
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return ans;
    }
    
    int peek() {
        int ans = s2.top();
        return ans;
    }
    
    bool empty() {
        return (s2.empty()?true:false);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */