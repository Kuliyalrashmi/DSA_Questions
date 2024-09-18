class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(auto i:nums)
        {
            temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end() ,[](string s1,string s2)
             {
                 return (s2+s1)<(s1+s2);
             });
        if(temp[0]=="0")
        {
            return "0";
        }
        string ans="";
        for(auto i:temp)
        {
            ans+=i;
        }
        return ans;
            
    }
};