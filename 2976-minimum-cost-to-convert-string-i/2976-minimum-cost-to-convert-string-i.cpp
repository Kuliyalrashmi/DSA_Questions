class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
       vector<vector<int>>matrix(26,vector<int>(26,INT_MAX));
       for(int i=0;i<26;i++)
       {
           matrix[i][i]=0;
       }
       int n=original.size();
       for(int i=0;i<n;i++)
       {
           matrix[original[i]-'a'][changed[i]-'a']=min(matrix[original[i]-'a'][changed[i]-'a'],cost[i]);
       }
       for(int k=0;k<26;k++)
       {
           for(int i=0;i<26;i++)
           {
               for(int j=0;j<26;j++)
               {
                   if(matrix[i][k]!=INT_MAX&&matrix[k][j]!=INT_MAX)
                   {
                       matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                   }
               }
           }
       }
       long long ans=0;
       n=source.size();
       for(int i=0;i<n;i++)
       {
           if(matrix[source[i]-'a'][target[i]-'a']==INT_MAX)
           {
               return -1;
           }
           ans+=matrix[source[i]-'a'][target[i]-'a'];
       }
       return ans;
    }
};