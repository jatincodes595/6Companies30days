#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    
    // 1st Way
    // long long countWays(int m)
    // {
    //     return m/2+1;
    // }
    
    // 2nd way
    long long countWays(int m)
    {
        if(m==1)
        return 1;
        if(m==2)
        return 2;
        
        vector<int> dp(m+1,0);
        dp[1]=1;         // {1}
        dp[2]=2;        // {1 1} or {2}
        for(int i=3;i<=m;i++)
        {
            dp[i]=dp[i-2]+1;
        }
        return dp[m];
    }
    
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends