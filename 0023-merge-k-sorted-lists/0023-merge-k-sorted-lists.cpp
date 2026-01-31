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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return {};
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        for(auto it:lists){
            if(!it) continue;
            pq.push({it->val, it});
        }
        if(pq.empty()) return {};
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(!pq.empty()){
            auto[val, node]=pq.top();
            pq.pop();
            ListNode* nn=new ListNode(val);
            curr->next=nn;
            curr=nn;
            if(node->next){
                pq.push({node->next->val, node->next});
            }
        }
        return dummy.next;
    }
};