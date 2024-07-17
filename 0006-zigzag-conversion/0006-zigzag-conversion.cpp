class Solution {
public:
    string convert(string s, int numRows) {
         int n=s.size();
        if(numRows==1)
        {
            return s;
        }
        if(n<numRows)
        {
            return s;
        }
        int index=0,dir=-1;
        string ans;
        vector<char>temp[numRows];
        for(auto i :s)
        {
            temp[index].push_back(i);
            if(index==0||index==numRows-1)
            {
                dir*=-1;
            }
            index+=dir;
        }
        for(auto s:temp)
        {
            for(auto ch:s)
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};