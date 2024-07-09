class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int flag=0,n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[i]<s2[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return true;
        }
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(s2[i]<s1[i])
            {
                flag=1;
                break;
            }
        }
        return flag==0?true:false;
    }
};