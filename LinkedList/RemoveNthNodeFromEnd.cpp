/* Leetcode Question no 19 Remove Nth Node From End Of The List
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL&&n==1)
        {
            return NULL;
        }
        int length=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        int count=length-n;
        if(count==0)
        {
            head=head->next;
            return head;
        }
        temp=head;
        while(count>1)
        {
            temp=temp->next;
            count--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
