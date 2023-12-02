/* 2 December 2023
Leetcode Question no 1160 Find Words That Can Be Formed By Characters
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.
*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>arr(26,0);
        int ans=0;
        for(auto &ch:chars)
        {
            arr[ch-'a']++;
        }
        for(auto &ch:words)
        {
            vector<int>temp(26,0);
            for(auto &i:ch)
            {
                temp[i-'a']++;
            }
            bool flag=1;
            for(int k=0;k<26;k++)
            {
                if(arr[k]<temp[k])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                ans+=ch.size();
            }
        }
        return ans;
    }
};
