#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> st;

    for(char c : postfix) {
        if(isalnum(c)) {
            // Operand: push as a string
            st.push(string(1, c));
        } else if(isOperator(c)) {
            // Pop two operands
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Combine into "(op1 op op2)"
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}
