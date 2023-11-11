/* Leetcode Question no 14 Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string str1=strs[0],str2=strs[n-1],answer="";
        int len=str1.size();
        for(int i=0;i<len;i++)
        {
            if(str1[i]==str2[i])
            {
                answer+=str1[i];
            }
            else
            {
                break;
            }
        }
        return answer;
    }
};
