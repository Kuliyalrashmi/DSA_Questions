class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),start=0,end=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                start=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s1[i]!=s2[i])
            {
                end=i;
                break;
            }
        }
        swap(s1[start],s1[end]);
        return s1==s2;
    }
};