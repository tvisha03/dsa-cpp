#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};

// 🔁 Helper function to create a cycle at given position
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* cycleStart = nullptr;
    ListNode* tail = head;
    int index = 0;

    while (tail->next != nullptr) {
        if (index == pos) {
            cycleStart = tail;
        }
        tail = tail->next;
        index++;
    }
    tail->next = cycleStart; // Create cycle
}

int main() {
    // Create list: 3 → 2 → 0 → -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create a cycle: connect -4 → 2 (pos = 1)
    createCycle(head, 1);

    Solution solution;
    bool result = solution.hasCycle(head);

    if (result) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle." << endl;
    }

    return 0;
}
