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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        int divide=size/k;
        int rem=size%k;
        vector<ListNode*>ans(k,NULL);
        temp=head;
        ListNode*prev=NULL;
        for(int i=0;i<k;i++)
        {
            ans[i]=temp;
            for(int count=1;count<=divide+(rem>0?1:0);count++)
            {
                prev=temp;
                temp=temp->next;
            }
            if(prev!=NULL)
            {
                 prev->next=NULL;
            }
            rem--;

        }
        return ans;
    }
};