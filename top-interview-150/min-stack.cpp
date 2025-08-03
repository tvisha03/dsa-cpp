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
#include <iostream>
#include <stack>
using namespace std;
int main() {
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Minimum: " << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl; // Output: 0
    cout << "Minimum: " << minStack.getMin() << endl; // Output: -2
    
    return 0;
}