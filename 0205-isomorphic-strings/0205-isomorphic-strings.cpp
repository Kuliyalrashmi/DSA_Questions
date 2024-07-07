class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int x=s.size(),y=t.size();
        if(x!=y)
        {
            return false;
        }
        int hash1[256]={0};
        int hash2[256]={0};
        for(int i=0;i<x;i++)
        {
            if(hash1[s[i]]!=hash2[t[i]])
            {
                return false;
            }
            hash1[s[i]]=i+1;
            hash2[t[i]]=i+1;
        }
        return true;
    }
};