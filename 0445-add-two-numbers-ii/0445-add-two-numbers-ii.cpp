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

    ListNode* reversell(ListNode* root){
        if (!root || !root->next) return root;
        ListNode* prev = root;
        ListNode* curr = root->next;
        prev->next = nullptr;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ll1=reversell(l1);
        ListNode* ll2=reversell(l2);
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        int carry=0;
        while(ll1||ll2||carry){
            int sum=carry;

            if(ll1){
                sum+=(ll1->val);
                ll1=ll1->next;
            }
            if(ll2){
                sum+=(ll2->val);
                ll2=ll2->next;
            }
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
        }
        return reversell(dummy->next);
    }
};