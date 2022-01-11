#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int findMinRec(int arr[], int i, int sumCalculated,int sumTotal,vector<vector<int>> &dp)
    {
        // If we have reached last element.  Sum of one
        // subset is sumCalculated, sum of other subset is
        // sumTotal-sumCalculated.  Return absolute difference
        // of two sums.
        if (i == 0)
            return abs((sumTotal - sumCalculated)- sumCalculated);
     
        if(dp[i][sumCalculated]!=-1)
        {
            return dp[i][sumCalculated];
        }
        // For every item arr[i], we have two choices
        // (1) We do not include it first set
        // (2) We include it in first set
        // We return minimum of two choices
        dp[i][sumCalculated]=min(findMinRec(arr, i - 1, sumCalculated + arr[i - 1],sumTotal,dp),findMinRec(arr, i - 1, sumCalculated, sumTotal,dp));
        return dp[i][sumCalculated];
    }
	int minDifference(int arr[], int n)  
	{ 
	    // Compute total sum of elements
        int sumTotal = 0;
        for (int i = 0; i < n; i++)
            sumTotal += arr[i];
 
        vector<vector<int>> dp(n+1,vector<int>(sumTotal+1,-1));
        return findMinRec(arr, n, 0, sumTotal,dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends