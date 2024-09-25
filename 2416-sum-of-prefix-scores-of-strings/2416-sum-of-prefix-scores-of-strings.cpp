class Solution {
public:
    struct trieNode{
        int count=0;
        trieNode* child[26];
    };
    trieNode* getTrieNode()
    {
        trieNode*newNode=new trieNode();
        for(int i=0;i<26;i++)
        {
            newNode->child[i]=NULL;
        }
        newNode->count=0;
        return newNode;
    }
    void insert(string &str,trieNode*root)
    {
        trieNode*temp=root;
        for(char ch:str)
        {
            int index=ch-'a';
            if(!temp->child[index])
            {
                temp->child[index]=getTrieNode();
            }
            temp->child[index]->count+=1;
            temp=temp->child[index];
        }
    }
    int calculate(string &str,trieNode* root)
    {
        trieNode*temp=root;
        int score=0;
        for(char ch:str)
        {
            score+=temp->child[ch-'a']->count;
            temp=temp->child[ch-'a'];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        trieNode*root=getTrieNode();
        for(string i:words)
        {
            insert(i,root);
        }
        vector<int>ans;
        for(auto i:words)
        {
           ans.push_back(calculate(i,root));
        }
        return ans;
    }
};