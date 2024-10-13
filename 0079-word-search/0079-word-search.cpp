class Solution {
public:
    bool search(vector<vector<char>>& board,string& word,int index,int m,int n,int row,int col)
    {
        if(index>=word.size())
        {
            return true;
        }
        if(row<0||row>=m||col<0||col>=n||board[row][col]!=word[index])
        {
            return false;
        }
        char temp=board[row][col];
        board[row][col]='*';
        bool ans=search(board,word,index+1,m,n,row-1,col)||
                 search(board,word,index+1,m,n,row+1,col)||
                 search(board,word,index+1,m,n,row,col-1)||
                 search(board,word,index+1,m,n,row,col+1);
        board[row][col]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0]&&search(board,word,0,m,n,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};