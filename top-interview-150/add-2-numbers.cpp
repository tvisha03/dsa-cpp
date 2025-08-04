
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cctype>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=l1, *prev=nullptr;
        int carry=0;
        while(l1||l2||carry){
            int sum=carry+(l1?l1->val:0)+(l2?l2->val:0);

            if(l1){
                l1->val=sum%10;
                carry=sum/10;
                prev=l1;
                l1=l1->next;
            }else{
                prev->next=new ListNode(sum%10);
                carry=sum/10;
                prev=prev->next;

            }
            if(l2) l2=l2->next;
        }
        return head;
        
    }
};

int main(){
    // Example usage:
    Solution solution;
    
    // Create first number: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    // Create second number: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    // Output the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}