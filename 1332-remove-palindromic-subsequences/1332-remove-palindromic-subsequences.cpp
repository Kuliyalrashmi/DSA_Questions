class Solution {
public:
    bool isPalindrome(string s)
    {
        int start=0,end=s.size()-1;
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
    int removePalindromeSub(string s) {
        if(isPalindrome(s))
        {
            return 1;
        }
        return 2;
    }
};