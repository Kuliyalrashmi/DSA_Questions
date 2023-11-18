/* Leetcode Question No 25 Reverse Nodes in K Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        for(int i=0;i<k;i++)
        {
            if(temp==NULL)
            {
                return head;
            }
            temp=temp->next;
        }
        ListNode*curr=head,*prev=NULL,*forward=NULL;
        int count=0;
        while(curr!=NULL&&count<k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward!=NULL)
       {
           head->next=reverseKGroup(curr,k);
       }
       head=prev;
       return head;
    }
};
