/* 
What is Trie?

A trie, also known as a prefix tree, is a tree-like data structure used for storing a dynamic set of strings or associative arrays where the keys are usually strings. 
The word "trie" comes from the word "retrieval" because it is particularly well-suited for retrieval tasks.
Tries are commonly used in applications that require the fast and efficient lookup of a key represented by a string.
In a trie, each node represents a character of a string. The edges between nodes represent the links between characters.
The root of the trie is typically an empty string, and each path from the root to a leaf node represents a string stored in the trie.

Application Of Trie

Spell Checking and Auto-Completion:
Tries are used in spell-checking algorithms to suggest corrections for misspelled words.
They are also employed in auto-complete systems to quickly retrieve words based on partial input.

IP Routing Tables:
Tries are utilized in routers to store and efficiently search IP addresses in routing tables. 
This allows for fast lookup of the next hop in a routing decision.

Symbol Tables in Compilers:
Compilers use symbol tables to manage identifiers (variables, functions, etc.). 
Tries are suitable for implementing symbol tables, enabling quick lookup of identifiers.

Contacts and Phonebook Applications:
Tries can be employed to efficiently store and search contact information in phonebook applications.
This is especially useful for searching contacts based on prefixes.

Network Security and Firewalls:
Tries are used in intrusion detection systems and firewalls for efficient matching of patterns or signatures in network traffic.

Time Complexities of Trie:
Insertion=O(length of Word)
Deletion=O(length of word)
Searching=O(length of word)
*/
/* Implemetation of Trie 
Leetcode Question no 208
Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.

boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.

boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 */
class Trie {
public:
    Trie() {
        
    }
    struct trie
    {
        bool isWord;
        trie *child[26];
    };
    trie *newNode()
    {
        trie*temp=new trie();
        temp->isWord=false;
        for(int i=0;i<26;i++)
        {
            temp->child[i]=NULL;
        }
        return temp;
    }

    trie *root=newNode();

    void insert(string word) {
        int n=word.size();
        trie*curr=root;
        for(int i=0;i<n;i++)
        {
            if(curr->child[word[i]-'a']==NULL)
            {
                curr->child[word[i]-'a']=new trie();
            }
            curr=curr->child[word[i]-'a'];
        }
        curr->isWord=true;
    }
    
    bool search(string word) {
        int n=word.size();
        trie*curr=root;
        for(int i=0;i<n;i++)
        {
            if(curr->child[word[i]-'a']==NULL)
            {
                return false;
            }
            curr=curr->child[word[i]-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        trie*curr=root;
        for(int i=0;i<n;i++)
        {
            if(curr->child[prefix[i]-'a']==NULL)
            {
                return false;
            }
            curr=curr->child[prefix[i]-'a'];
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

