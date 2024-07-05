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
        vector<int>temp;
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=curr->next;
        int index=1;
        while(forward)
        {
            if((prev!=NULL&&prev->val>curr->val&&forward->val>curr->val)||(prev!=NULL&&prev->val<curr->val&&forward->val<curr->val))
            {
                temp.push_back(index);
            }
            prev=curr;
            curr=forward;
            forward=forward->next;
            index++;
        }
        if(temp.size()<2)
        {
            return {-1,-1};
        }
        int min_dist=INT_MAX,max_dist=INT_MIN;
        // for(int i=0;i<temp.size();i++)
        // {
        //     cout<<temp[i]<<" ";
        // }
        max_dist=temp.back()-temp.front();
        for(int i=0;i<temp.size()-1;i++)
        {
            min_dist=min(min_dist,temp[i+1]-temp[i]);
        }
        return {min_dist,max_dist};
    }
};