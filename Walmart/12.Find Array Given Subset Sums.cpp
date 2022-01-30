class Solution{

  public:
  int sumTotal;
  vector<vector<int>> dp;
    int findMinRec(int arr[], int i, int sumCal)
    {
        // If we have reached last element.  Sum of one
        // subset is sumCalculated, sum of other subset is
        // sumTotal-sumCalculated.  Return absolute difference
        // of two sums.
        if (i == 0)
            return abs((sumTotal - sumCal)- sumCal);
     
        if(dp[i][sumCal]!=-1)
        {
            return dp[i][sumCal];
        }
        // For every item arr[i], we have two choices
        // (1) We do not include it first set
        // (2) We include it in first set
        // We return minimum of two choices
        dp[i][sumCal]=min(findMinRec(arr, i - 1, sumCal+ arr[i - 1]),findMinRec(arr, i - 1, sumCal));
        return dp[i][sumCal];
    }
	int minDifference(int arr[], int n)  
	{ 
	    // Compute total sum of elements
        sumTotal = 0;
        for (int i = 0; i < n; i++)
            sumTotal += arr[i];
 
        dp.resize(n+1,vector<int>(sumTotal+1,-1));
        return findMinRec(arr, n, 0);
	} 
};