class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start=1,end=*max_element(nums.begin(),nums.end());
        while(start<end)
        {
            int mid=start+(end-start)/2;
            int operation=0;
            for(auto num:nums)
            {
                if((operation+=(num-1)/mid)>maxOperations)
                {
                    break;
                }
            }
            if(operation<=maxOperations)
            {
                end=mid;
            }
            else
            {
                start=mid+1;
            }
        }
        return end;
    }
};