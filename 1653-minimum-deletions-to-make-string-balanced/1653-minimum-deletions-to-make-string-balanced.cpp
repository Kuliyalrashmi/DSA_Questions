class Solution {
public:
    int minimumDeletions(string s) {
        int countA=0,countB=0;
        int ans=INT_MAX,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                countA++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                countA--;
            }
            ans=min(ans,countA+countB);
            if(s[i]=='b')
            {
                countB++;
            }
        }
        return ans;
    }
};