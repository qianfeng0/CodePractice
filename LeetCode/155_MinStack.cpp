/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

#include <stdio.h>
#include <stdint.h>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT32_MAX;
    }
    
    void push(int x) {
        if (x <= min){
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        int temp = s.top();
        s.pop();
        if (temp == min){
            min = s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
private:
    int min;
    std::stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    return 0;
}