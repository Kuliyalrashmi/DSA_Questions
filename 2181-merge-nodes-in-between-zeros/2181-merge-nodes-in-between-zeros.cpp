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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*Newhead=new ListNode(-1);
        ListNode*temp=Newhead;
        ListNode*ptr=head;
        int sum=0;
        ptr=ptr->next;
        while(ptr)
        {
            sum+=ptr->val;
            if(ptr->val==0)
            {
                temp->next=new ListNode(sum);
                temp=temp->next;
                sum=0;
            }
            ptr=ptr->next;
        }
        return Newhead->next;
    }
};