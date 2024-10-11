class Solution {
public:
    int check_palindrome(string str,int start,int end)
    {
        while(start>=0&&end<str.size()&&str[start]==str[end])
        {
            start--;
            end++;
        }
        return end-start-1;
    }
    string longestPalindrome(string s) {
        int size=s.size();
        int start_index=0,max_length=0,length=0;
        for(int i=0;i<size;i++)
        {
            int len1=check_palindrome(s,i,i);
            int len2=check_palindrome(s,i,i+1);
            max_length=max(len1,len2);
            if(max_length>length)
            {
                start_index=i-(max_length-1)/2;
                length=max_length;
            }
        }
        return s.substr(start_index,length);
    }
};