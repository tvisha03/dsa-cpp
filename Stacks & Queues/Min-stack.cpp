#include <stack>
#include <iostream>
using namespace std;

class MinStack {
    stack<int> st;
    int minVal;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minVal=val;
        }else{
            if(val<=minVal){
                st.push(minVal);
                minVal=val;
            }
        }
        st.push(val);
        
    }
    
    void pop() {
        if(st.top()==minVal){
            st.pop();
            minVal=st.top();
            st.pop();
        }else{
            st.pop();
        }
        
    }
    
    int top() {
        return st.top();
        
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

 int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl; // Returns 0
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -2
    return 0;