/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast=head,*slow=head,*ptr;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                ptr=slow;
                slow=head;
                while(slow!=ptr)
                {
                    slow=slow->next;
                    ptr=ptr->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};