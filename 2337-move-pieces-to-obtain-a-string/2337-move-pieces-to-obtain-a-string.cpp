class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0,m=start.size();
        while(i<m||j<m)
        {
            while(i<m&&start[i]=='_')
            {
                i++;
            }
            while(j<m&&target[j]=='_')
            {
                j++;
            }
            if(i==m||j==m)
            {
                break;
            }
            if(start[i]!=target[j])
            {
                return false;
            }
            if(start[i]=='L')
            {
                if(i<j)
                {
                    return false;
                }
            }
            if(start[i]=='R')
            {
                if(i>j)
                {
                    return false;
                }
            }
            i++;
            j++;
        }
        return i==m&&j==m;
    }
};