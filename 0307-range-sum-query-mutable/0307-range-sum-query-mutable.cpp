class NumArray {
public:
    int n,len;
    vector<int>blocks,arr;
    NumArray(vector<int>& nums) {
        n=nums.size();
        len=ceil(sqrt(n));
        arr=nums;
        blocks.resize(len,0);
        for(int i=0;i<n;i++)
        {
            blocks[i/len]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int change=val-arr[index];
        arr[index]=val;
        int bi=index/len;
        blocks[bi]+=change;
    }
    
    int sumRange(int left, int right) {
        int ans=0;
        int sb=left/len,eb=right/len;
        if(sb==eb)
        {
            for(int i=left;i<=right;i++)
            {
                ans+=arr[i];
            }
            return ans;
        }
        int i=left;
        while(i/len==sb)
        {
            ans+=arr[i++];
        }
        i=right;
        while(i/len==eb)
        {
            ans+=arr[i--];
        }
        for(i=sb+1;i<eb;i++)
        {
            ans+=blocks[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */