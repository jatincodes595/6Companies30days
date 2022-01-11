class Solution{
	public:
    int cnt1=0,cnt=0;
    vector<int> vis,vis1;
    // it is used to find the no of connected components
    void dfs(int i,vector<int> adj[])
    {
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(vis[x]==0)
            dfs(x,adj);
        }
    }
    // it is used to find the no of connected components after removing the given edge
    void dfs1(int i,vector<int> adj[],int c,int d)
    {
        vis1[i]=1;
        for(auto x:adj[i])
        {
            if(vis1[x]==0)
            {
                if((i==d && x==c) || (i==c && x==d))
                continue;
                dfs1(x,adj,c,d);
            }
            
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vis.resize(V);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj);
                cnt++;
            }
            
        }
        vis1.resize(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis1[i]==0)
            {
            dfs1(i,adj,c,d);
            cnt1++;
            }
        }
        if(cnt1==cnt)
        return 0;
        else
        return 1;
        // Code here
    }
};