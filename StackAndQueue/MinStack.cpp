/* Leetcode Question No 155 Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

*/
class MinStack {
public:
    vector<int>v1,v2;
    MinStack() {
        
    }
    
    void push(int val) {
        v1.push_back(val);
        if(v2.size()==0||val<=v2.back())
        {
            v2.push_back(val);
        }
    }
    
    void pop() {
        if(v1.back()==v2.back())
        {
            v2.pop_back();
        }
        v1.pop_back();
    }
    
    int top() {
        return v1.back();
    }
    
    int getMin() {
        return v2.back();
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
