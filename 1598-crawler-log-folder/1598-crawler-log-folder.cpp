class Solution {
public:
    int minOperations(vector<string>& logs) {
       stack<int>st;
       st.push(0);
       int n=logs.size();
       for(int i=0;i<n;i++)
       {
           if(logs[i]=="./")
           {
               continue;
           }
           else if(logs[i]=="../")
           {
               if(st.top()==0)
               {
                   continue;
               }
               int no=st.top();
               st.pop();
               st.push(--no);
           }
           else
           {
               int no=st.top();
               st.pop();
               st.push(++no);
           }
       }
        return st.top();
    }
};