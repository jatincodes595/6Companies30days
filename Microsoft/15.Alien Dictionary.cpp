class Solution{
    public:
    // main algo used in Topological sort
    string findOrder(string dict[], int N, int K) 
    {
        map<char,vector<char>> mp;
        map<char,int> indegree;
        for(int i=0;i<N-1;i++)
        {
            int si=min(dict[i].size(),dict[i+1].size());
            for(int j=0;j<si;j++)
            {
                if(dict[i][j]!=dict[i+1][j])
                {
                    mp[dict[i][j]].push_back(dict[i+1][j]);
                    indegree[dict[i+1][j]]++;
                    break;
                }
            }
        }
        // for(auto x:mp)
        // {
        //     cout<<x.first<<"-->";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        // for(auto x:indegree)
        // {
        //     cout<<"{"<<x.first<<"-->"<<x.second<<"}";
        // }
        queue<char> q;
        string ans="";
        for(auto x:mp)
        {
            if(indegree[x.first]==0)
            {
                q.push(x.first);
                ans+=x.first;
            }
        }
        while(!q.empty())
        {
            char no=q.front();
            q.pop();
            for(auto x:mp[no])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                    ans+=x;
                }
            }
        }
        //cout<<ans<<"\n";
        return ans;
    }
};