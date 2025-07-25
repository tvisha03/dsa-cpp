#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix (helper function)
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        else if(isOperator(c)) {
            while(!st.empty() && precedence(c) < precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            if(c == '^') {
                while(!st.empty() && st.top() == '^') {
                    postfix += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && precedence(c) <= precedence(st.top())) {
                    postfix += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Convert infix to prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    // Swap '(' with ')' and vice versa
    for(int i = 0; i < infix.length(); i++) {
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
