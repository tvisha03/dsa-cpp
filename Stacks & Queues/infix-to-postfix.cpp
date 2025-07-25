#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(char c : infix) {
        // Operand → Add to output
        if(isalnum(c)) {
            postfix += c;
        }
        // Left bracket → Push to stack
        else if(c == '(') {
            st.push(c);
        }
        // Right bracket → Pop till '('
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else if(isOperator(c)) {
            while(!st.empty() && precedence(c) <= precedence(st.top())) {
                if(c == '^' && st.top() == '^') break; // right-associative check
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop any remaining operators
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Driver Code
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
