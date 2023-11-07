/* Number of Inversions
There is an Integer array A of size N. count the no of inversions inversions in an array 
can be defined as the number of pairs of i and j such that i<j and A[i]>A[j].
*/

/* Brute Force Approach*/
int numberOfInversions(vector<int>&a, int n) {
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j]&&i<j)
            {
                count++;
            }
        }
    }
    return count;
}


/* Using Merge Sort */
int merge(vector<int>&a,int start,int mid,int end)
{
    int count=0;
    int n1=mid-start+1;
    int n2=end-mid;
    int*left=new int[n1];
    int *right=new int[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=a[start+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=a[mid+i+1];
    }
    int k=start,index1=0,index2=0;
    while(index1<n1&&index2<n2)
    {
        if(left[index1]<=right[index2])
        {
            a[k]=left[index1];
            index1++;
        }
        else
        {
            a[k]=right[index2];
            index2++;
            count+=n1-index1;
        }
        k++;
    }
    while(index1<n1)
    {
        a[k++]=left[index1++];
    }
    while(index2<n2)
    {
        a[k++]=right[index2++];
    }
    delete []left;
    delete []right;
    return count;
}
int mergeSort(vector<int>&a,int start,int end)
{   int count=0;
    if(start>=end)
    {
        return count;
    }
    int mid=start+(end-start)/2;
    count+=mergeSort(a,start,mid);
    count+=mergeSort(a,mid+1,end);
    count+=merge(a,start,mid,end);
    return count;
}
int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a,0,n-1);
}
