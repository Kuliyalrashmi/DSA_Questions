/* Leetcode Question 53 MAximum Subarray
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. 
  A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable.
  Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum.
  Among all the sums calculated, we will consider the maximum one.
  */
 int maxSubArray(vector<int>& nums) {
        int sum=0,max_sum=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            max_sum=max(sum,max_sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return max_sum;
    }
