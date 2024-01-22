/*    22-Jan-2024

  
Leetcode Question no 645 Set Mismatch
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>answer;
        int arr[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i]>1)
            {
                answer.push_back(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==0)
            {
                answer.push_back(i);
                break;
            }
        }
        return answer;
    }
};
