class Solution {
public:
    bool solve(vector<vector<char>>&board,int index,int m,int n,string word,int i,int j)
    {
        if(index>=word.size())
        {
            return true;
        }
        if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[index])
        {
            return false;
        }
        char temp=board[i][j];
        board[i][j]='*';
        bool ans=solve(board,index+1,m,n,word,i-1,j)||
                 solve(board,index+1,m,n,word,i+1,j)||
                 solve(board,index+1,m,n,word,i,j-1)||
                 solve(board,index+1,m,n,word,i,j+1);
        board[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0]&&solve(board,0,m,n,word,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};