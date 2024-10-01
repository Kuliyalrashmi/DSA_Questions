class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftSum=0,rightSum=0;
        if(n==k)
        {
            for(int i=0;i<n;i++)
            {
                leftSum+=cardPoints[i];
            }
            return leftSum;
        }
        for(int i=0;i<k;i++)
        {
            leftSum+=cardPoints[i];
        }
        int maxSum=leftSum;
        int end=n-1;
        for(int i=k-1;i>=0;i--)
        {
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[end];
            maxSum=max(maxSum,leftSum+rightSum);
            end--;
        }
        return maxSum;
    }
};