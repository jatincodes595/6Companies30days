class Solution {
public:
    // main algo is Topological sort
    vector<int> ans;
    vector<vector<int>> adj;
    void BFS(int n)
    {
           //kahn's alogorithm of finding tpological sort uing BFS
           vector<int> indegree(n,0);
           for(auto x:adj)
           {
                  for(auto y:x)
                         indegree[y]++;
           }
           queue<int> q;
           for(int i=0;i<n;i++)
           {
                  if(indegree[i]==0)
                         q.push(i);
           }
           while(!q.empty())
           {
                  int u=q.front();
                  q.pop();
                  ans.push_back(u);
                  for(auto x:adj[u])
                  {
                         indegree[x]--;
                         if(indegree[x]==0)
                                q.push(x);
                  }
           }
        // if indegree is more than 0 then we cannot do the tasks..because there is cycle
        for(int i=0;i<n;i++)
        {
            if(indegree[i]>0)
            {
                ans.clear();
            }
        }
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) 
    {
        adj.clear();
        adj.resize(num);
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        ans.clear();
        BFS(num);
        return ans;
    }
};