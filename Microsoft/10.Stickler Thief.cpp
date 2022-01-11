// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution
{
    public:
    
    int FindMaxSum(int hval[], int n)
    {
        if (n == 0)
        return 0;
        if (n == 1)
            return hval[0];
        if (n == 2)
            return max(hval[0], hval[1]);
 
        // dp[i] represent the maximum value stolen
        // so far after reaching house i.
        int dp[n];
     
        // Initialize the dp[0] and dp[1]
        dp[0] = hval[0];
        dp[1] = max(hval[0], hval[1]);
     
        // Fill remaining positions
        for (int i = 2; i<n; i++)
        {
            dp[i] = max(hval[i]+dp[i-2], dp[i-1]);
        }
            
     
        return dp[n-1];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends