#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
        cout << "Pushed: " << x << endl;
    }
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1; // Indicating stack is empty
        }
        int popped = q.front();
        q.pop();
        cout << "Popped: " << popped << endl;
        return popped;
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1; // Indicating stack is empty
        }
        return q.front();
    }
    int Size() {
        return q.size();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.top() << endl;
    s.pop();
    cout << "Top element is: " << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    return 0;
}