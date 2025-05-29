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
    if (!head || !head->next) return nullptr;  
    int size = 0;
    ListNode* curr = head;
    while (curr) {
        size++;
        curr = curr->next;
    }
    int mid = size / 2;
    curr = head;
    for (int i = 0; i < mid - 1; i++) {
        curr = curr->next;
    }

    curr->next = curr->next->next;

    return head;
}

};