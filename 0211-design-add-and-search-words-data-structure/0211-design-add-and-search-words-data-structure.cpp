class WordDictionary {
public:
    WordDictionary() {
        
    }
    struct trie
    {
        trie *child[26];
        bool isEnd=false;
    };
    trie* getNode()
    {
        trie*temp=new trie();
        for(int i=0;i<26;i++)
        {
            temp->child[i]=NULL;
        }
        return temp;
    }
    trie* root=new trie();
    void addWord(string word) {
        trie *temp=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            int index=word[i]-'a';
            if(temp->child[index]==NULL)
            {
                temp->child[index]=new trie();
            }
            temp=temp->child[index];
        }
        temp->isEnd=true;
    }
    bool solve(trie *root,string word)
    {
        trie* temp=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(word[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(temp->child[j]!=NULL)
                    {
                        if(solve(temp->child[j],word.substr(i+1)))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else if(temp->child[index]==NULL)
            {
                return false;
            }
            temp=temp->child[index];
        }
        return temp->isEnd;
    }
    bool search(string word) {
       return solve(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */ 