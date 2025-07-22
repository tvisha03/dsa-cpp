#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
    Node* head;
    int count;
public:
    Stack() {
        head = nullptr;
        count = 0;
    }
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        count++;
    }
    int pop() {
        if (head == nullptr) {
            return -1; // Stack is empty
        }
        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return val;
    }
    int top() {
        if (head == nullptr) {
            return -1; // Stack is empty
        }
        return head->data;
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        return head == nullptr;
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