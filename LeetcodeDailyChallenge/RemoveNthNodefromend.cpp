/*  3-Mar-2024
Leetcode Question no 19 Remove Nth node form end of list
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
    int solve(ListNode*head)
    {
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL&&n==1)
        {
            return NULL;
        }
        int len=solve(head);
        int pos=len-n;
        if(pos==0)
        {
            head=head->next;
        }
        while(pos>1)
        {
            temp=temp->next;
            pos--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
