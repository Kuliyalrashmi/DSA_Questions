class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size(),ans=0;
        for(int i=1;i<n;i++)
        {
            int prev=i-1;
            int next=(i+1)%n;
            if(colors[prev]!=colors[i]&&colors[i]!=colors[next])
            {
                ans++;
            }
        }
        if(colors[0]!=colors[1]&&colors[0]!=colors[n-1])
        {
            ans++;
        }
        return ans;
    }
};