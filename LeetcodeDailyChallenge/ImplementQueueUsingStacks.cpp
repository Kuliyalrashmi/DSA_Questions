/*    29-Jan-2024
Leetcode Question no 232 Implement A Queue Using Stacks
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, 
  peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively.
You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

  */

class MyQueue {
public:
   stack<int> st, rst;
    MyQueue() {
    }
    void push(int x) {
        st.push(x);
    }
    int pop() {
        if (rst.empty())
            transfer(rst, st);
        int val = rst.top();
        rst.pop();
        return val;
    }
    int peek() {
        if (rst.empty())
            transfer(rst, st);
        return rst.top();
    }

    void transfer(stack<int> &s1, stack<int> &s2) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    bool empty() {
        return st.empty() && rst.empty();
    }

};
