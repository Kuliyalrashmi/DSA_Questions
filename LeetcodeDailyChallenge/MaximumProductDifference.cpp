/*     18-Dec-2023
Leetcode Question no 1913  Maximum Product Difference Between Two Pairs
The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference
between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
Return the maximum such product difference.
*/

/* Approach 1 Using Sorting */
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int num1=nums[0]*nums[1];
        int num2=nums[n-1]*nums[n-2];
        return num2-num1;
    }
};


/* Approach 2 Without Using Sorting */

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        int Largest=0,Second_Largest=0,Smallest=INT_MAX,Second_Smallest=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=Largest)
            {
                Second_Largest=Largest;
                Largest=nums[i];
            }
            else if(nums[i]<Largest&&nums[i]>Second_Largest)
            {
               Second_Largest=nums[i];
            }
            if(nums[i]<=Smallest)
            {
                Second_Smallest=Smallest;
                Smallest=nums[i];
            }
            else if(nums[i]>Smallest&&nums[i]<Second_Smallest)
            {
                Second_Smallest=nums[i];
            }
        }
        return (Largest*Second_Largest)-(Smallest*Second_Smallest);
    }
};
