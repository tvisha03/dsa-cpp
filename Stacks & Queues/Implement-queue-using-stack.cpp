#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1; // Indicating queue is empty
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }
    int peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1; // Indicating queue is empty
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    int size() {
        return s1.size() + s2.size();
    }
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element is: " << q.peek() << endl; // Output: 10
    cout << "Dequeue element: " << q.dequeue() << endl; // Output: 10
    cout << "Front element is: " << q.peek() << endl; // Output: 20
    cout << "Queue size: " << q.size() << endl; // Output: 2
    return 0;
}