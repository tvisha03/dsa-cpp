/*2. Write the code to find the Fibonacci series upto the nth term.
This problem asks to generate the Fibonacci sequence up to the nth term. In this sequence, each number is the sum of the two preceding ones, starting from 0 and 1.

The goal is to calculate and display all Fibonacci numbers from the 0th to the nth term.
Example for n = 10:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34   
(Writing: Start with 0 and 1 → 0+1=1 → 1+1=2 → 1+2=3 → 2+3=5 → and so on.)
*/

#include <iostream>
using namespace std;
// using iterative approach
int fibonacci(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    int i=0, j=1, k;

    for(int index=2;index<=n;index++){
        k=i+j;
        i=j;
        j=k;
    }
    return k;

}

int fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<fibonacci(i)<<" ";
    }


    return 0;
}