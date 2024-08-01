class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string str=details[i];
            int no=0;
            no=(no*1)+(str[11]-'0');
            no=(no*10)+(str[12]-'0');
            if(no>60)
            {
                ans++;
            }
        }
        return ans;
    }
};