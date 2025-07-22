#include <iostream>
#include <vector>
using namespace std;

class Stack{
    int size;
    int *arr;
    int top;
    public:
    Stack(){
        top=-1;
        size=1000;
        arr=new int[size];
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    int pop(){
        int x=arr[top];
        top--;
        return x;
    }
    int Top(){
        return arr[top];
    }
    int Size(){
        return top+1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.Top() << endl; // Output: 30
    cout << "Stack size: " << s.Size() << endl; // Output: 3
    cout << "Popped element: " << s.pop() << endl; // Output: 30
    cout << "Top element: " << s.Top() << endl; // Output: 20
    cout << "Stack size: " << s.Size() << endl; // Output: 2
    cout << "Popped element: " << s.pop() << endl; // Output: 20
    cout << "New top element: " << s.Top() << endl; // Output: 10
    return 0;
}
