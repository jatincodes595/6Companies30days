int s=0;
void rec(vector<vector<int>>&bracket,int i,int j,string&ans)
{
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
 string matrixChainOrder(int p[], int n){
       vector<vector<int>>dp(n,vector<int>(n,0));
       vector<vector<int>>bracket(n+1,vector<int>(n+1,0));
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
                            dp[i][j]=x;
                            bracket[i][j]=k;
                        }
                    }
                }
            }
       }
       string ans;
       rec(bracket,1,n-1,ans);
       return ans;
    }
