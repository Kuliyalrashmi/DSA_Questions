class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
       int start=0,end=minutes;
       int max_ans=0;
       for(int i=0;i<minutes;i++)
       {
           max_ans+=customers[i]*grumpy[i];
       }
        int curr_ans=max_ans;
      while(end<n)
      {
          curr_ans+=(customers[end]*grumpy[end]);
          curr_ans-=(customers[start]*grumpy[start]);
          max_ans=max(max_ans,curr_ans);
          start++,end++;
      }
      for(int i=0;i<n;i++)
      {
             max_ans+=(customers[i]*(1-grumpy[i]));
      }
        return max_ans;
    }
};