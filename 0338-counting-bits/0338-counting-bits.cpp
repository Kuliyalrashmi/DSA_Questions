class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int count=0,num=0;
        for(int i=0;i<=n;i++)
        {
            count=0;
            num=i;
            while(num!=0)
            {
                if(num%2==1)
                {
                    count++;
                }
                num=num/2;
            }
             ans.push_back(count);
        }
        return ans;
    }
};