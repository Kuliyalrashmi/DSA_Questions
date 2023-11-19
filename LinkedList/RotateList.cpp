/* Leetcode Question No 61 Rotate List
Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
        {
            return head;
        }
        int total=0,count=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            total++;
            temp=temp->next;
        }
        k=k%total;
        if(k==0)
        {
            return head;
        }
        k=total-k;
        temp=head;
        ListNode*prev=NULL,*X=NULL,*Y=NULL; 
        while(temp)
        {
           count++;
           if(count==k)
           {
                X=temp;
                Y=temp->next;
           }
           prev=temp;
           temp=temp->next;
        }
        prev->next=head;
        X->next=NULL;
        head=Y;
        return head;

    }
};
