class Solution {
public:
    void solve(string &digits,string temp,vector<string>&ans,vector<string>&mp,int index)
    {
        if(index == digits.size()){
            if(digits.size()==temp.size())
            {
                ans.push_back(temp);
            }
            return;
        }

        int val = digits[index] - '0';

        string tp = mp[val];
        

        for(int i = 0; i <tp.size() ;i++){
            temp.push_back(tp[i]);
            solve(digits,temp,ans,mp,index+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>ans;
        string temp="";
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,temp,ans,mp,0);
        return ans;
    }
};