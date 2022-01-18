class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) 
    {
        // two no are always in AP ...therefore 2 will be minimum val
        if(n<=2)
        return n;
        int res = 2;
        vector<vector<int>> dp(n, vector<int>(20000, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)  
            {
                // added 10000 beacuse the no can be negative ..therefore to make it positive we used it
                int d = A[j] - A[i] + 10000;
                // d is the difference 
                dp[j][d] = max(2, dp[i][d] + 1);
                
                res = max(res, dp[j][d]);
            }
        }
        return res;
    }
};