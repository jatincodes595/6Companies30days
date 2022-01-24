class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,-1,1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> r;
        int m = matrix.size();
        if (m == 0)
            return r;
        int n = matrix[0].size();
        if (n == 0)
            return r;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) 
        {
            dfs(matrix, pacific, i, 0);// left boudary
            dfs(matrix, atlantic, i, n-1); // right boundary

        }
        for (int j = 0; j < n; j++) {
            dfs(matrix, pacific, 0, j);// upper boundary
            dfs(matrix, atlantic, m-1, j); // lower boundary
        }

        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                // if both are true that means from there water can go to both oceans
                if (pacific[i][j] && atlantic[i][j])
                    r.push_back({i,j});
            }
        }
        return r;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) 
    {
        int n = matrix.size();// rows
        int m = matrix[0].size(); //columns

        visited[i][j] = true;
        
        for(int k=0;k<4;k++)
        {
            int newi=i+x[k];
            int newj=j+y[k];
            //up down left right
            // the next element should be more than or equal to ...beacuse we are going in reverse ..i.e from boundary to inside
            if(newi>=0 && newi<n && newj>=0 && newj<m && visited[newi][newj]!=true && matrix[newi][newj]>=matrix[i][j])
            {
                dfs(matrix,visited,newi,newj);
            }
        }
        

    }
};