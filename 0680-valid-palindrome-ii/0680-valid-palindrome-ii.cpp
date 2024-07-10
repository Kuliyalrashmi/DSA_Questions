class Solution {
public:
    bool isPalindrome(string &s , int start,int end)
    {
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        if(isPalindrome(s,0,j))
        {
            return true;
        }
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return (isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1));
            }
        }
        return true;
    }
};