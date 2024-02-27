/*  Leetcode Question no 204 Count Primes
Given an integer n, 
return the number of prime numbers that are strictly less than n.
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
        {
            return 0;
        }
        vector<bool>sieve(n,true);
        int count=1;
        sieve[0]=false,sieve[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(sieve[i]==true)
            {
               for(int j=i*i;j<n;j+=i)
               {
                   if(sieve[j]==true)
                   {
                       count++;
                   }
                   sieve[j]=false;
               }
            }
        }
        return n-count-1;
    }
};
