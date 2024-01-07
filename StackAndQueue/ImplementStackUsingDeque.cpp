/*       
Design a data structure to implement a stack, using only deque (double-ended queue). It should support the following operations :

push(X): Pushes an element X into the stack. Returns true if the element is pushed into the stack, otherwise false.

pop(): Pops the top element from the stack. Returns -1 if the stack is empty, otherwise, returns the popped element.

top(): Returns the topmost element of the stack. In case the stack is empty, it returns -1.

isEmpty() : Returns true if the stack is empty, otherwise false.

size(): Returns the number of elements currently present in the stack.
Following type of queries denote these operations :

Type 1 : for push(X) operation.

Type 2 : for pop() operation.

Type 3 : for top() operation.

Type 4 : for isEmpty() operation.

Type 5 : for size() operation.

*/


#include <bits/stdc++.h> 
class Stack
{
    int capacity;
    deque<int>d;
public:
    // Initialize your data structure.
    Stack()
    {
        capacity=0;
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        d.push_back(x);
        capacity++;
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(isEmpty())
        {
            return -1;
        }
        int element=d.back();
        d.pop_back();
        capacity--;
        return element;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(isEmpty())
        {
            return -1;
        }
        return d.back();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
       if(capacity==0)
       {
           return true;
       }
       return false;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return capacity;
    }
};
