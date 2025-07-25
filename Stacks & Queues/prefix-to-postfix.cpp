#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert Prefix to Postfix
string prefixToPostfix(string prefix) {
    stack<string> st;

    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            // Operand → push to stack
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            // Operator → pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form postfix: operand1 operand2 operator
            string expr = op1 + op2 + c;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
