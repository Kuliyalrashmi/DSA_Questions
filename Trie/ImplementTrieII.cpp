/* 
Implement Trie – II
Problem Statement:  Implement a data structure ”TRIE” from scratch. Complete some functions.

1) Trie(): Initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.

Note:
1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

*/
#include <bits/stdc++.h> 
class Trie{

    public:

    Trie(){
       
    }
    struct trie{
        bool isWord;
        trie *child[26];
        int cnprefix=0;
        int cntEndwith=0;
    };
    trie *newNode()
    {
        trie * temp=new trie();
        temp->isWord=false;
        for(int i=0;i<26;i++)
        {
            temp->child[i]=NULL;
        }
        return temp;
    }
    trie*root=newNode();
    void insert(string &word){
        int n=word.size();
        trie*curr=root;
        for(int i=0;i<n;i++)
        {
            if(curr->child[word[i]-'a']==NULL)
            {
                curr->child[word[i]-'a']=new trie();
            }
            curr=curr->child[word[i]-'a'];
            (curr->cnprefix)++;
        }
        curr->isWord=true;
        curr->cntEndwith++;
    }

    int countWordsEqualTo(string &word){
        trie *curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(curr->child[word[i]-'a']!=NULL)
            {
                curr=curr->child[word[i]-'a'];
            }
            else
            {
                return 0;
            }
        }
        return curr->cntEndwith;
    }

    int countWordsStartingWith(string &word){
        trie *curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(curr->child[word[i]-'a']!=NULL)
            {
                curr=curr->child[word[i]-'a'];
            }
            else
            {
                return 0;
            }
        }
        return curr->cnprefix;
    }

    void erase(string &word){
        trie*curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(curr->child[word[i]-'a']!=NULL)
            {
                curr=curr->child[word[i]-'a'];
                curr->cnprefix--;
            }
        }
        curr->cntEndwith--;
        curr->isWord=false;
    }
};
