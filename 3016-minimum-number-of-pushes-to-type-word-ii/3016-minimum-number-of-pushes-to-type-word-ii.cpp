class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(char curr:word)
        {
            mp[curr]=(mp.find(curr)!=mp.end())?mp[curr]+1:1;
        }
        vector<char>temp;
        for(auto i:mp)
        {
            temp.push_back(i.first);
        }
        sort(temp.begin(),temp.end(),[&](char a ,char b)
             {
                 return mp[b]<mp[a];
             });
        int k1=0,k2=1,k3=2;
        for(char ch :temp)
        {
            k1+=mp[ch]*k2;
            if(k3<9)
            {
                k3++;
            }
            else
            {
                k3=2;
                k2++;
            }
        }
     return k1;
    }
};