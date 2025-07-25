#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            // Operand → push as string
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            // Operator → pop two operands
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Combine: operator + operand1 + operand2
            string expr = c + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
