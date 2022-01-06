// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) 
    {
        int dp[K+1][N];
        // put oth col and 0th row equal to 0
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=K;i++)
        {
            int maxdiff=0;
            for(int j=1;j<N;j++)
            {
                if(j!=1)
                maxdiff=max(maxdiff,dp[i-1][j-1]-A[j-1]);
                else // on first day
                maxdiff=dp[i-1][j-1]-A[j-1];
                dp[i][j]=max(dp[i][j-1],maxdiff+A[j]);
            }
        }
        // for(int i=0;i<=K;i++)
        // {
        //     for(int j=0;j<N;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[K][N-1];
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends