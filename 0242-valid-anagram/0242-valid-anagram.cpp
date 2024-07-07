class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26]={0};
        for(auto i:s)
        {
            hash[i-'a']++;
        }
        for(auto i:t)
        {
            hash[i-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};