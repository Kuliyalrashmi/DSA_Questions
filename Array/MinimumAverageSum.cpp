/*Q1 Leetcode-2256. Minimum Average Difference*/
/*Approach 1 */
int minimumAverageDifference(vector<int>& nums) {
        int min_diff=INT_MAX,ans=-1;
        long long  sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        long long  left=0;
        long long right=0;
        for(int i=0;i<n;i++)
        {
            left+=nums[i];
            right=sum-left;
            long long avg1=left/(i+1);
            long long avg2=(i==n-1)?0:right/(n-(i+1));
            int diff=abs(avg1-avg2);
            if(diff<min_diff)
            {
                min_diff=diff;
                ans=i;
            }
        }
        return ans;
    }
/*Time Complexity=O(n)
  space complexity=O(1)*/




/*Approach 2(Prefix Sum Array )*/
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long >prefix(n,0);
        prefix[0]=nums[0];
        int min_diff=INT_MAX,ans=-1;
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            int left=prefix[i]/(i+1);
            int right=(i==n-1)?0:(prefix[n-1]-prefix[i])/(n-i-1);
            if(abs(left-right)<min_diff)
            {
                if(min_diff==0)
                {
                    return i;
                }
                min_diff=abs(left-right);
                ans=i;
            }
        }
        return ans;
    }
/*Time complexity=O(n)
  Space Complexity=O(n)
*/
