/* 
Leetcode Question no 1814 Count Nice Pairs in an Array
You are given an array nums that consists of non-negative integers.
Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21.
A pair of indices (i, j) is nice if it satisfies all of the following conditions:
0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

*/
class Solution {
public:
    int mod=1e9+7;
    int rev(int no)
    {
        int newNo=0;
        while(no)
        {
          newNo=newNo*10+(no%10);
          no=no/10;
        }
        return newNo;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size(),count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int temp=nums[i]-rev(nums[i]);
            if(mp.find(temp)!=mp.end())
            {
                int value=mp[temp];
                mp[temp]=value+1;
                count=(count%mod+mp[temp]%mod)%mod;
            }
            else
            {
                mp[temp]=0;
            }
        }
        return count%mod;
    }
};
