class Solution {
public:
    void dfs(vector<vector<int>>& a,int i,int j)
    {
        a[i][j]=0;
        for(int z=0;z<a.size();z++)
        {
            if(a[j][z]==1)
            {
                dfs(a,j,z);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int cnt=0;
        int n=isConnected.size();
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    cnt++;
                    dfs(isConnected,i,j);
                }
                    
            }
        }
        return cnt;
    }
};