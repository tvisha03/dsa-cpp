#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> st;

    // Traverse from right to left
    for(int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if(isalnum(c)) {
            // Operand: push as string
            st.push(string(1, c));
        } else if(isOperator(c)) {
            // Operator: pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Combine into infix: (op1 operator op2)
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}
