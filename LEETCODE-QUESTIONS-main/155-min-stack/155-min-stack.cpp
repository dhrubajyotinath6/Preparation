//https://leetcode.com/problems/min-stack/solution/

class MinStack {
    
private:
    
    stack<int> st;
    stack<pair<int,int>> minSt;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        // We always put the number onto the main stack.
        st.push(val);
        
        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (minSt.empty() || val < minSt.top().first) {
            minSt.push({val, 1});
        }
        
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (val == minSt.top().first) {
            minSt.top().second++;
        }
    }
    
    void pop() {
        
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (st.top() == minSt.top().first) {
            minSt.top().second--;
        }
        
        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minSt.top().second == 0) {
            minSt.pop();
        }
        
        // And like before, pop the top of the main stack.
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top().first;
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