class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int no1=0,no2=0,target=0;
        int n=firstWord.size();
        for(int i=0;i<n;i++)
        {
            no1=no1*10+(firstWord[i]-'a');
        }
        n=secondWord.size();
        for(int i=0;i<n;i++)
        {
            no2=no2*10+(secondWord[i]-'a');
        }
        no1+=no2;
        n=targetWord.size();
        for(int i=0;i<n;i++)
        {
            target=target*10+(targetWord[i]-'a');
        }
        return target==no1;
    }
};