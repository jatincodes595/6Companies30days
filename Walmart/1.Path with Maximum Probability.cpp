class Solution {
public:
    // just a variation of dijkstra
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) 
    {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++) 
        {
            adj[edges[i][0]].push_back({edges[i][1], pro[i]});
            adj[edges[i][1]].push_back({edges[i][0], pro[i]});   
        }
        // making a visted array
        vector<int> vis(n, 0);
        // max heap
        priority_queue<pair<double, int>> q;
        // {max_prob,node}
        q.push({(double)1.0, start});
        
        vector<double> mx(n, (double)0.0);
        mx[start] = 1.0;
        
        while(!q.empty()) 
        {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int node = top.second;
            if(!vis[node]) 
            {
                vis[node]=1;
                for(auto x: adj[node]) 
                {
                    // if new probablity is more than update it
                    if (mx[x.first] < x.second*proba) 
                    {
                        mx[x.first] = x.second*proba;
						q.push({mx[x.first], x.first});
                    }
                }
            }
        }
        return mx[end];
    }
};