#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends


/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/
int cnt;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={0,1,-1,1,-1,0,1,-1};
bool IsSafe(int x,int y,int n,int m,int a[SIZE][SIZE])
{
       if(x>=0 && x<n && y>=0 && y<m && a[x][y]==1)
              return true;
       return false;
}

void BFS(int x,int y,int n,int m,int a[SIZE][SIZE])
{       
       a[x][y]=0;
       cnt++;
       queue<pair<int,int>> q;
       q.push({x,y});
       while(!q.empty())
       {
              auto u = q.front();
              q.pop();
              for(int i=0;i<8;i++)
              {
                     int newx=u.first+dx[i];
                     int newy=u.second+dy[i];
                     if(IsSafe(newx,newy,n,m,a))
                     {     cnt++;
                            a[newx][newy]=0;
                            q.push({newx,newy});
                     }
              }
       }
}

int findMaxArea(int n, int m, int a[SIZE][SIZE] )
{   int maxarea=INT_MIN;
    
       for(int i=0;i<n;i++)
       {
              for(int j=0;j<m;j++)
              {
                     if(a[i][j]==1)
                     {
                            cnt=0;
                            BFS(i,j,n,m,a);
                            maxarea=max(maxarea,cnt);
                     }
              }
       }
       return maxarea;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends