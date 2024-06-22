class NumArray {
    vector<int>arr,segment;
    int n;
public:
    void build(int left,int right,int index)
    {
        if(left>=right)
        {
            segment[index]=arr[left];
            return;
        }
        int mid=left+(right-left)/2;
        build(left,mid,2*index+1);
        build(mid+1,right,2*index+2);
        segment[index]=segment[2*index+1]+segment[2*index+2];
    }
    NumArray(vector<int>& nums) {
       arr=nums;
       n=nums.size();
        segment.resize(4*n);
        build(0,n-1,0);
    }
    void update1(int start,int end,int index,int updated_ind,int updated_val)
    {
        if(start==end)
        {
            segment[index]+=updated_val;
            return;
        }
        int mid=start+(end-start)/2;
        if(updated_ind<=mid)
        {
            update1(start,mid,2*index+1,updated_ind,updated_val);
        }
        else
        {
            update1(mid+1,end,2*index+2,updated_ind,updated_val);
        }
        segment[index]=segment[2*index+1]+segment[2*index+2];
    }
    void update(int index, int val) {
        int change=val-arr[index];
        arr[index]=val;
        update1(0,n-1,0,index,change);
    }
    int getSum(int ql,int qr,int sl,int sr,int index)
    {
        if(ql<=sl&&qr>=sr)
        {
            return segment[index];
        }
        if(qr<sl||ql>sr)
        {
            return 0;
        }
        int mid=sl+(sr-sl)/2;
        return getSum(ql,qr,sl,mid,2*index+1)+getSum(ql,qr,mid+1,sr,2*index+2);
    }
    int sumRange(int left, int right) {
        return getSum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */