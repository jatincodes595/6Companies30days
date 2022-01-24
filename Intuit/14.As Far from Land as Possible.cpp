class Solution {
public:
    int x[4]={0,0,-1,1};
    int y[4]={-1,1,0,0};
    // it is just a basic multi source BFS
    int maxDistance(vector<vector<int>>& grid) 
    {
            queue<pair<int,pair<int,int>>> q;
            int n = grid.size();
            int zero = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j] == 1) 
                        q.push({0,{i,j}});
                    else
                    {
                        zero++;
                        grid[i][j] = INT_MAX;
                    }
                }
            }
            // if there is no land or no water
            if(q.empty() || zero == 0) 
                return -1;
        

            int ans=0;

            while(!q.empty())
            {
                auto top = q.front(); 
                q.pop();
                int curr_dist = top.first;
                int x1 = top.second.first;
                int y1 = top.second.second;

                for(int i=0;i<4;i++)
                {
                    int xnew = x1+x[i];
                    int ynew = y1+y[i];

                    if(xnew>=0 && xnew<n && ynew>=0 && ynew<n && grid[xnew][ynew]>curr_dist+1)
                    {
                        grid[xnew][ynew]=curr_dist+1;
                        q.push({curr_dist+1,{xnew,ynew}});
                        ans = max(ans,grid[xnew][ynew]);
                    }
                }
            }

            return ans;
    }
};