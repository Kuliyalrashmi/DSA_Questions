/* Leetcode Question No 148 Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
*/
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


/* using Merge Sort */

class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode*temp=new ListNode(-1);
        ListNode*curr=temp;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                curr->next=l1;
                curr=curr->next;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                curr=curr->next;
                l2=l2->next;
            }
        }
        while(l1)
        {
            curr->next=l1;
            curr=curr->next;
            l1=l1->next;
        }
        while(l2)
        {
            curr->next=l2;
            curr=curr->next;
            l2=l2->next;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode*fast=head,*slow=head,*prev=NULL;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode*l1=sortList(head);
        ListNode*l2=sortList(slow);
        ListNode*ans=merge(l1,l2);
        return ans;
    }
};
