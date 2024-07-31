class Solution {
public:
    int dp[1001][1001];
    int solve(int index,int remain,int n,vector<vector<int>>& books,int width,int height)
    {
        if(index>=n)
        {
            return height;
        }
        if(dp[index][remain]!=-1)
        {
            return dp[index][remain];
        }
        int bookH=books[index][1];
        int bookW=books[index][0];
        int keep=INT_MAX,skip=INT_MAX;
        if(bookW<=remain)
        {
            keep=solve(index+1,remain-bookW,n,books,width,max(height,bookH));
        }
        skip=height+solve(index+1,width-bookW,n,books,width,bookH);
        return dp[index][remain]=min(keep,skip);
        
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        memset(dp,-1,sizeof(dp));
        int maxH=0;
        maxH=solve(0,shelfWidth,n,books,shelfWidth,maxH);
        return maxH;
    }
};