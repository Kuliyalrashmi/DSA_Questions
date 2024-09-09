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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int topRow=0,bottomRow=m-1,leftcol=0,rightcol=n-1;
        while(head)
        {
           for(int i=leftcol;i<=rightcol;i++)
           {
               if(!head)
               {
                   return ans;
               }
               ans[topRow][i]=head->val;
               head=head->next;
           }
           topRow++;
           for(int i=topRow;i<=bottomRow;i++)
           {
               if(!head)
               {
                   return ans;
               }
               ans[i][rightcol]=head->val;
               head=head->next;
           }
           rightcol--;
           for(int i=rightcol;i>=leftcol;i--)
           {
               if(!head)
               {
                   return ans;
               }
               ans[bottomRow][i]=head->val;
               head=head->next;
           }
           bottomRow--;
           for(int i=bottomRow;i>=topRow;i--)
           {
               if(!head)
               {
                   return ans;
               }
               ans[i][leftcol]=head->val;
               head=head->next;
           }
           leftcol++;
        }
        return ans;
    }
};