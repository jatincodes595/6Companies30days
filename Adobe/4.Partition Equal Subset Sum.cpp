class Solution{
public:
// the problem is same as Subset Sum Problem
    vector<vector<int>> dp;
    int subsetSum(int a[], int n, int sum)
    {
        
        
        if (sum == 0)
            return 1;
            
        if (n <= 0)
            return 0;
      
       
        if (dp[n][sum] != -1)
            return dp[n - 1][sum];
      
        
        if (a[n - 1] > sum)
            return dp[n][sum] = subsetSum(a, n - 1, sum);
        else
        {
            return dp[n][sum] = subsetSum(a, n - 1, sum) || subsetSum(a, n - 1, sum - a[n - 1]);
        }
    }
    int equalPartition(int N, int arr[])
    {
        dp.clear();
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2==1)
        return false;
        else
        {
            dp.resize(N+1,vector<int>(sum/2+1,-1));
            if(subsetSum(arr, N, sum/2))
            return true;
            else
            return false;
        }
        
    }
};