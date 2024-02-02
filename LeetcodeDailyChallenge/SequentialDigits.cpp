/*  2-Feb-2024
Leetcode Question no 1291 Sequential Digits
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

*/
/* Approach 1 using BFS*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=8;i++)
        {
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            if(temp>=low&&temp<=high)
            {
                ans.push_back(temp);
            }
            int ones=temp%10;
            if(ones+1<=9)
            {
                q.push(temp*10+(ones+1));
            }
        }
        return ans;
    }
};

/* Approach 2*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
      vector<int>possible={12,23,34,45,56,67,78,89,
                           123,234,345,456,567,678,789,
                           1234,2345,3456,4567,5678,6789,
                           12345,23456,34567,45678,56789,
                           123456,234567,345678,456789,
                           1234567,2345678,3456789,
                           12345678,23456789,
                           123456789
                         };
    int n=possible.size();
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
       if(possible[i]>=low&&possible[i]<=high)
       {
           ans.push_back(possible[i]);
       }
    }
    return ans;
    }
};
