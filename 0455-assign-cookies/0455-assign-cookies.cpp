class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int i=0,j=0,count=0;
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int m=g.size(),n=s.size();
        while(i<m&&j<n)
        {
            if(s[j]>=g[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};