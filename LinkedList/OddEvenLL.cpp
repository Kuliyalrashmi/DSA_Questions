/*
Leetcode Question no 328 Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode*EvenHead=NULL,*OddHead=NULL;
        ListNode*EvenTail=NULL,*OddTail=NULL;
        int i=1;
        while(head!=NULL)
        {
            if(i%2==0)
            {
                ListNode*temp=new ListNode(head->val);
                if(EvenHead==NULL)
                {
                    EvenHead=temp;
                    EvenTail=temp;
                }
                else
                {
                    EvenTail->next=temp;
                    EvenTail=EvenTail->next;
                }
            }
            else
            {
                ListNode*temp=new ListNode(head->val);
                if(OddHead==NULL)
                {
                    OddHead=temp;
                    OddTail=temp;
                }
                else
                {
                    OddTail->next=temp;
                    OddTail=OddTail->next;
                }
            }
            head=head->next;
            i++;
        }
        OddTail->next=EvenHead;
        return OddHead;
    }
};
