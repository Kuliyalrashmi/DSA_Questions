/*  22 Feb 2024
Leetcode Question no 997 Find The Town Judge
In a town, there are n people labeled from 1 to n. 
There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person 
labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array,
then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        int size=trust.size();
        for(int i=0;i<size;i++)
        {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==n-1&&outdegree[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};




/* Using Single Vector */
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int>answer(n+1);
    if(n==1)
    {
      return 1;
    }
    for(int i=0;i<trust.size();i++)
    {
        
        answer[trust[i][0]]--;
        answer[trust[i][1]]++;
    }
    for(int i=0;i<=n;i++)
    {
         if(answer[i]==n-1)
        {
            return i;
        }
    }
    return -1;
    }
};
