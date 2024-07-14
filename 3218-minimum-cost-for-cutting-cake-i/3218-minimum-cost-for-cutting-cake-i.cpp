class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());
        int vi=0,hi=0;
        int ans=0;
        int numv=1,numh=1;
        while(hi<horizontalCut.size()&&vi<verticalCut.size())
        {
            if(verticalCut[vi]<=horizontalCut[hi])
            {
                ans+=horizontalCut[hi]*numh;
                numv++;
                hi++;
            }
            else
            {
                ans+=verticalCut[vi]*numv;
                numh++;
                vi++;
            }
        }
        while(hi<horizontalCut.size())
        {
            ans+=horizontalCut[hi]*numh;
            hi++;
        }
         while(vi<verticalCut.size())
        {
            ans+=verticalCut[vi]*numv;
            vi++;
        }
        return ans;
    }
};