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
    ListNode* merge(ListNode*l1,ListNode*l2)
    {
        ListNode *head=new ListNode(-1);
        ListNode*tail=head;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                tail->next=l1;
                l1=l1->next;
            }
            else
            {
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1)
        {
            tail->next=l1;
        }
        else if(l2)
        {
            tail->next=l2;
        }
        return head->next;
    }
    ListNode*mergeSort(int start,int end,vector<ListNode*>&lists)
    {
        if(start>=end)
        {
            return lists[start];
        }
        if(start+1==end)
        {
            return merge(lists[start],lists[end]);
        }
        int mid=start+(end-start)/2;
        ListNode*left=mergeSort(start,mid,lists);
        ListNode*right=mergeSort(mid+1,end,lists);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
        {
            return {};
        }
        return mergeSort(0,n-1,lists);
    }
};