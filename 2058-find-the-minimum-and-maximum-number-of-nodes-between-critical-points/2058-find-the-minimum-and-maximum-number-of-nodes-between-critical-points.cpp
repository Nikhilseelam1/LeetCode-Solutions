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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int mx=-1;
        int mn=-1;
        ListNode *temp=head;
        head=head->next;
        int ind=1;
        while(head->next!=nullptr){
            if((temp->val > head->val && head->val < head->next->val) || 
            temp->val<head->val && head->val > head->next->val){
                if(mx!=-1 && mn!=-1){
                    cout<<1<<" ";
                    mini=min(mini,ind-mn);
                    maxi=max(maxi,ind-mx);
                }
                if(mx==-1) mx=ind;
                mn=ind;
            }
            ind++;
            temp=head;
            head=head->next;

        }
        if(mini==INT_MAX) return {-1,-1};
        return {mini,maxi};
    }
};