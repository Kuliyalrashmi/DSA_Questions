class Solution {
public:
    struct trie
    {
        trie *child[26];
        string word;
        bool isEnd=false;
    };
    trie *getNode()
    {
        trie* temp=new trie();
        for(int i=0;i<26;i++)
        {
            temp->child[i]=NULL;
        }
        temp->word="";
        return temp;
    }
    void insert(trie *root,string word)
    {
        trie *temp=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(temp->child[index]==NULL)
            {
                temp->child[index]=getNode();
            }
            temp=temp->child[index];
        }
        temp->isEnd=true;
        temp->word=word;
    }
    int del_row[4]={1,-1,0,0};
    int del_col[4]={0,0,1,-1};
    void solve(vector<vector<char>>&board,int i,int j,int m,int n,trie*root,vector<string>&ans)
    {
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='*'||root->child[board[i][j]-'a']==NULL)
        {
            return;
        }
        int index=board[i][j]-'a';
        root=root->child[index];
        if(root->isEnd==true)
        {
            ans.push_back(root->word);
            root->isEnd=false;
        }
        char temp=board[i][j];
        board[i][j]='*';
        for(int k=0;k<4;k++)
        {
            int new_i=i+del_row[k];
            int new_j=j+del_col[k];
            solve(board,new_i,new_j,m,n,root,ans);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string>ans;
        int m=board.size(),n=board[0].size();
        trie*root=getNode();
        for(auto word:words)
        {
            insert(root,word);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int index=board[i][j]-'a';
                if(root->child[index]!=NULL)
                {
                    solve(board,i,j,m,n,root,ans);
                }
            }
        }
        return ans;
    }
};