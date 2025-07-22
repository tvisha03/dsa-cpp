#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int start,end,currSize,maxSize;
    public:
    Queue(){
        arr=new int[16];
        start=-1;
        end=-1;
        currSize=0;
    }
    Queue(int maxSize){
        (*this).maxSize=maxSize;
        arr=new int[maxSize];
        start=-1;
        end=-1;
        currSize=0;
    }
    void push(int x){
        if(currSize==maxSize){
            cout << "Queue is full" << endl;
            return;
        }
        if(end==-1){
            start=0;
            end=0;
        }else{
            end=(end+1)%maxSize;
        }
        arr[end]=x;
        cout << "Pushed: " << x << endl;
        currSize++;
        }
        int pop(){
            if(start==-1){
                cout << "Queue is empty" << endl;
                return -1; // Indicating queue is empty
            }
            int popped=arr[start];
            if(currSize==1){
                start=-1;
                end=-1;
            }else{
                start=(start+1)%maxSize;
            }
            currSize--;
            return popped;
        }
        int Top(){
            if(start==-1){
                cout << "Queue is empty" << endl;
                return -1; // Indicating queue is empty
            }
            return arr[start];
        }
        int Size(){
        if(start==-1){
            return 0;
        }else{
            return currSize;
        }
        }
    };

int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element: " << q.Top() << endl; // Output:
    cout << "Queue size: " << q.Size() << endl; // Output: 3
    cout << "Popped element: " << q.pop() << endl; // Output:
    cout << "Front element: " << q.Top() << endl; // Output: 20
    cout << "Queue size: " << q.Size() << endl; // Output:
    cout << "Popped element: " << q.pop() << endl; // Output: 20
    cout << "New front element: " << q.Top() << endl; // Output:
    cout << "Queue size: " << q.Size() << endl; // Output: 1
    cout << "Popped element: " << q.pop() << endl; // Output:
    cout << "Queue size: " << q.Size() << endl; // Output:
    cout << "Popped element: " << q.pop() << endl; // Output: Queue is empty
    cout << "Queue size: " << q.Size() << endl; // Output:
    return 0;
}