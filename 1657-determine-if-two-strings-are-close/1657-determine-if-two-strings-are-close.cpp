class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        int m=word1.size();
        int n=word2.size();
        if(m!=n)
        {
            return false;
        }
        for(auto i:word1)
        {
            hash1[i-'a']++;
        }
        for(auto i:word2)
        {
            hash2[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash1[i]==0&&hash2[i]==0)
            {
                continue;
            }
            if(hash1[i]!=0&&hash2[i]!=0)
            {
                continue;
            }
            return false;
        }
        sort(hash1.begin(),hash1.end());
        sort(hash2.begin(),hash2.end());
        return hash1==hash2;
    }
};