#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool BFS(int n,vector<vector<int>> adj)
    {
           //kahn's alogorithm of finding topological sort uing BFS
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
                  //cout<<u<<" ";
                  for(auto x:adj[u])
                  {
                         indegree[x]--;
                         if(indegree[x]==0)
                                q.push(x);
                  }
           }
           // done to find whether it has cycle or not
           for(auto x:indegree)
           {
               if(x>0)
               return false;
           }
           return true;
    }
    // the problem is simple to detect cycle ..if cycle is there then tasks can't be completed
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	    vector<vector<int>> adj(N);
	    for(auto x:prerequisites)
	    {
	        adj[x.first].push_back(x.second);
	    }
	    return BFS(N,adj);
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends