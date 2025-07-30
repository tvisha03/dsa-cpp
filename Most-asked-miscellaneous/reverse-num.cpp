/*1. Write a code to reverse a number
To reverse a number, you need to take the digits of the number and rearrange them in the opposite order.

Start by converting the number to a string, reverse that string, and then convert it back to an integer. This will give you the reversed version of the original number.
Example: If the number is 908701, take digits from last → 1, 0, 7, 8, 0, 9 → and make it 107809.
*/

#include <iostream>
using namespace std;

int revNum(int n){
    int r=0;
    while(n!=0){
        int digit=n%10;
        r=r*10+digit;
        n=n/10;
    }
    return r;
}

int main(){
    int number;
    cout<< "Enter a number: ";
    cin>>number;
    int reversedNumber = revNum(number);
    cout<< "Reversed number: " << reversedNumber << endl;
    return 0;
}