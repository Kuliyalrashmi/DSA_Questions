/*Leetcode 152 Maximum Product Subarray
Given an integer array nums, find a 
subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
*/

/* Brute Force Approach */
int subarrayWithMaxProduct(vector<int> &nums){
	int n=nums.size();
	int ans=nums[0];
	for(int i=0;i<n;i++)
	{
		int prod=nums[i];
		for(int j=i+1;j<n;j++)
		{
			ans=max(prod,ans);
			prod*=nums[j];
		}
		ans=max(prod,ans);
	}
	return ans;
}

/* Approch 2 Optimial */
int subarrayWithMaxProduct(vector<int> &nums){
	int n=nums.size();
	int ans=nums[0];
	for(int i=0;i<n;i++)
	{
		int prod=nums[i];
		for(int j=i+1;j<n;j++)
		{
			ans=max(prod,ans);
			prod*=nums[j];
		}
		ans=max(prod,ans);
	}
	return ans;
}
