class NumArray {
public:
    vector<int>arr,segment;
    int n;
    void build(int start,int end,int index)
    {
        if(start>=end)
        {
            segment[index]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(start,mid,2*index+1);
        build(mid+1,end,2*index+2);
        segment[index]=segment[2*index+1]+segment[2*index+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=nums;
        segment.resize(4*n);
        build(0,n-1,0);
    }
    void update1(int start,int end,int index,int updated_index,int updated_val)
    {
        if(start==end)
        {
            segment[index]+=updated_val;
            return;
        }
        int mid=start+(end-start)/2;
        if(updated_index<=mid)
        {
            update1(start,mid,2*index+1,updated_index,updated_val);
        }
        else
        {
            update1(mid+1,end,2*index+2,updated_index,updated_val);
        }
        segment[index]=segment[2*index+1]+segment[2*index+2];
    }
    void update(int index, int val) {
        int change=val-arr[index];
        arr[index]=val;
        update1(0,n-1,0,index,change);
    }
    int getsum(int start,int end,int query_start,int query_end,int index)
    {
        if(query_start<=start&&query_end>=end)
        {
            return segment[index];
        }
        if(query_start>end||query_end<start)
        {
            return 0;
        }
        int mid=start+(end-start)/2;
        return getsum(start,mid,query_start,query_end,2*index+1)+getsum(mid+1,end,query_start,query_end,2*index+2);
    }
    int sumRange(int left, int right) {
        return getsum(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */