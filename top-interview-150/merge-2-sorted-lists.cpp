




struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail=&dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next=l1?l1:l2;
        return dummy.next;
        
    }
};

#include <iostream>

using namespace std;

int main() {
    // Example usage:
    Solution solution;
    
    // Create first sorted list: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    // Create second sorted list: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    // Merge the two lists
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);
    
    // Print the merged list
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    
    return 0;
}