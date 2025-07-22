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

class Queue {
    Node* front;
    Node* rear;
    int count;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    int dequeue() {
        if (front == nullptr) {
            return -1; // Queue is empty
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        return val;
    }
    int peek() {
        if (front == nullptr) {
            return -1; // Queue is empty
        }
        return front->data;
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}