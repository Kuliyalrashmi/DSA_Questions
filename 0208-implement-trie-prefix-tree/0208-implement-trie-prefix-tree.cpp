class Trie {
public:
    Trie() {
        
    }
    struct trie
    {
        trie *child[26];
        bool isEnd=false;
    };
    trie *getNode()
    {
        trie*temp=new trie();
        for(int i=0;i<26;i++)
        {
            temp->child[i]=NULL;
        }
        return temp;
    }
    trie* root=getNode();
    void insert(string word) {
        trie*temp=root;
        for(int i=0;i<word.size();i++)
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
    
    bool search(string word) {
        trie* temp=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(temp->child[index]==NULL)
            {
                return false;
            }
            temp=temp->child[index];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        trie* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            int index=prefix[i]-'a';
            if(temp->child[index]==NULL)
            {
                return false;
            }
            temp=temp->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */