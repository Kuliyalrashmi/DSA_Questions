/*     12-Jan;2024
  
Leetcode Question no 1704 Determine If String Halves Are Alike
You are given a string s of even length. Split this string into two halves of equal lengths,
and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

*/

class Solution {
public:
    bool isVowel(char x)
    {
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
        {
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n/2;i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }
        for(int i=n/2;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                count--;
            }
        }
        return count==0;
    }
};
