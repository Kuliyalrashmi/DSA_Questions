class Solution {
public:
    string sortString(string s) {
        int hash[26]={0};
        for(auto i:s)
        {
            hash[i-'a']++;
        }
        string ans="";
        while(s.size()!=ans.size())
        {
            for(int i=0;i<26;i++)
            {
                if(hash[i]!=0)
                {
                    ans.push_back(i+'a');
                    hash[i]--;
                }
            }
            for(int i=25;i>=0;i--)
            {
                if(hash[i]!=0)
                {
                    ans.push_back(i+'a');
                    hash[i]--;
                }
            }
        }
        return ans;
    }
};