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
        auto [val, node]=pq.top();
        if(node==NULL) return {};
        ListNode* root=new ListNode(val);
        ListNode* curr=root;
        pq.pop();
        if(node->next){
            pq.push({node->next->val, node->next});
        }
        while(!pq.empty()){
            auto [val, node]=pq.top();
            pq.pop();
            if(node==NULL) continue;
            ListNode* nn=new ListNode(val);
            curr->next=nn;
            curr=nn;
            if(node->next)
            pq.push({node->next->val, node->next});
        }
        return root;

    }
};