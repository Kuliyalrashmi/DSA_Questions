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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        ListNode*temp=head;
        ListNode*ptr=NULL;
        while(temp!=NULL)
        {
            if(mp.find(temp->val)!=mp.end())
            {
                if(temp==head)
                {
                   temp=temp->next;
                   ptr=temp;
                   head=temp;
                }
                else
                {
                    ptr->next=temp->next;
                    temp=ptr;
                }
            }
            else
            {
                ptr=temp;
                temp=temp->next;
            }

        }
        return head;
    }
};