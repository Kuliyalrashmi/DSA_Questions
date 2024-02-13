/*   13-Feb-2024
  
Leetcode Question no 2108 Find First Palindromic String In The Array
Given an array of strings words, return the first palindromic string in the array.
If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.

*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word:words)
        {
            string original=word;
            reverse(word.begin(),word.end());
            if(original==word)
            {
                return original;
            }
        }
        return "";
    }
};
