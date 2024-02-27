/* Leetcode Question no 402 Remove K Digits
Given string num representing a non-negative integer num, and an integer k, 
  return the smallest possible integer after removing k digits from num.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
       int n=num.size();
       stack<char>st;
       string ans="";
       st.push(num[0]);
       for(int i=1;i<n;i++)
       {
           while(k>0&&!st.empty()&&num[i]<st.top())
           {
               k--;
               st.pop();
           }
           st.push(num[i]);

           if(st.size()==1&&num[i]=='0')
           {
               st.pop();
           }
       } 
       while(k&&!st.empty())
       {
           k--;
           st.pop();
       }
       while(!st.empty())
       {
           ans.push_back(st.top());
           st.pop();
       }
       reverse(ans.begin(),ans.end());
       if(ans.size()==0)
       {
           return "0";
       }
       return ans;
    }
};
