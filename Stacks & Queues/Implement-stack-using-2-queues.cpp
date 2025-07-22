#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    Stack() {}
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1; // Indicating stack is empty
        }
        int popped = q1.front();
        q1.pop();
        return popped;
    }
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1; // Indicating stack is empty
        }
        return q1.front();
    }
    int Size() {
        return q1.size();
    }
    bool isEmpty() {
        return q1.empty();
    }

};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.top() << endl; // Output: 30
    cout << "Stack size: " << s.Size() << endl; // Output: 3
    cout << "Popped element: " << s.pop() << endl; // Output: 30
    cout << "Top element is: " << s.top() << endl; // Output: 20
    cout << "Stack size: " << s.Size() << endl; // Output: 2
    return 0;
}