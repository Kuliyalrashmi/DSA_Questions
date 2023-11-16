/* Leetcode Question no 234 Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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
    ListNode*reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*forward=NULL;
        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }  
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow);
        fast=head;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
            {
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
