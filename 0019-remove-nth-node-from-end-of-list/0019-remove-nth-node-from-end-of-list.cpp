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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* node=head;
        while(node!=nullptr){
          node=node->next;
          size++;
        }
        if (n == size) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
        int a=size-n-1;
        size=0;
        node=head;
        while(size<a){
          node=node->next;
          size+=1;
        }
        ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;

    return head;
    }
};