/* Linear Search Algorithm
Time Complexity=O(n)
Space Complexity=O(1)
*/

int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            return i;
        }
    }
    return -1;
}
