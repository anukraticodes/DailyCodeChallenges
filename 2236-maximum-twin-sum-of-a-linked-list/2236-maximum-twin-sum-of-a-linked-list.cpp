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
    int pairSum(ListNode* head) {
        ListNode* tail=head;
        int size=0;
        while(tail){ tail=tail->next;
        size++;}
        // cout<<size<<endl;
        vector<int> vals(size/2);
        tail=head;
        for(int i=0; i<vals.size(); i++){
            vals[i]=tail->val;
            tail=tail->next;
        }
        int ans=INT_MIN;
        int j=vals.size()-1;
        while(tail){
            ans=max(ans, tail->val+vals[j]);
            j--;
            tail=tail->next;
        }
        return ans;
    }
};