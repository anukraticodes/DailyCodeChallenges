/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr;  // Edge case: 0 or 1 node

    // Step 1: Count size
    int size = 0;
    ListNode* curr = head;
    while (curr) {
        size++;
        curr = curr->next;
    }

    // Step 2: Go to node before middle
    int mid = size / 2;
    curr = head;
    for (int i = 0; i < mid - 1; i++) {
        curr = curr->next;
    }

    // Step 3: Delete middle node
    curr->next = curr->next->next;

    return head;
}

};