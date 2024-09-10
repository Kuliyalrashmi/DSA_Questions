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
    int GCD(int a,int b)
    {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a == b) return a;
        return (a > b) ? GCD(a - b, b) : GCD(a, b - a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*newHead=new ListNode(-1);
        ListNode*temp=newHead;
        if(!head->next)
        {
            return head;
        }
        while(head)
        {
            temp->next=new ListNode(head->val);
            temp=temp->next;
            if(head->next)
            {
               int no=GCD(head->val,head->next->val);
               temp->next=new ListNode(no);
               temp=temp->next;
            }
            head=head->next;
        }
        return newHead->next;
    }
};