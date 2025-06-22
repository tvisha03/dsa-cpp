#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start of the cycle
            }
        }

        return nullptr; // No cycle
    }
};

// Helper: Create cycle at given position
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
    tail->next = cycleStart;
}

int main() {
    // Create list: 3 → 2 → 0 → -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: connect -4 to node with value 2 (pos = 1)
    createCycle(head, 1);

    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);

    if (cycleStart != nullptr) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
