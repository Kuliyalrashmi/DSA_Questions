class Solution {
public:
    struct trie
    {
        trie *child[2];
        bool isEnd=false;
    };
    trie *getNode()
    {
        trie*temp=new trie();
        for(int i=0;i<2;i++)
        {
           temp->child[i]=NULL; 
        }
        return temp;
    }
    void insert(int num,trie*root)
    {
        trie*temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(temp->child[bit]==NULL)
            {
                temp->child[bit]=new trie();
            }
            temp=temp->child[bit];       
        }
    }
    int findMax(int num,trie*root)
    {
        trie*temp=root;
        int max_num=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(temp->child[1-bit]!=NULL)
            {
                max_num|=(1<<i);
                temp=temp->child[1-bit];
            }
            else
            {
                temp=temp->child[bit];
            }
        }
        return max_num;
    }
    int findMaximumXOR(vector<int>& nums) {
        trie*root=getNode();
        for(auto it:nums)
        {
            insert(it,root);
        }
        int ans=0;
        for (auto it: nums) 
        {
            ans = max(ans,findMax(it,root));
        }
        return ans;
    }
};