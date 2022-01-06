// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
// instead of using single value k we can use x1,y1 x2,y2 and then we can expand each value...but it is complex and chances of making mistakes is more
    int s=0;
    void rec(vector<vector<int>> bracket,int i,int j,string &ans)
    {
        // if both values are same then there is letter in between
        if(i==j)
        {
          ans+=('A'+s);
          s++;
          return ;
        }
          ans+='(';
          rec(bracket,i,bracket[i][j],ans);
          rec(bracket,bracket[i][j]+1,j,ans);
          ans+=')';
      
    }
    string matrixChainOrder(int p[], int n)
    {
       vector<vector<int>> dp(n,vector<int>(n,0));
       vector<vector<int>> bracket(n+1,vector<int>(n+1,0));
       for(int l=2;l<n;l++)
       {
            for(int i=1;i<n;i++)
            {
                int j=i+l-1;
                if(j<n)
                {
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++)
                    {
                        int x=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                        if(x<dp[i][j])
                        {
                            // we will go in a order of keeping brackets
                            dp[i][j]=x;
                            bracket[i][j]=k;
                        }
                    }
                }
            }
       }
    //   for(int i=0;i<=n;i++)
    //   {
    //       for(int j=0;j<=n;j++)
    //       cout<<bracket[i][j]<<" ";
    //       cout<<"\n";
    //   }
       string ans;
       rec(bracket,1,n-1,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
