class Solution {
public:
    // its main idea has been inspired from egg drop problem
    vector<vector<int>> dp;
    int helper(int left, int right)      
    {
        // if left is equal to right that means it is the ans so return 0
        if(left >= right)
        {
            return 0;
        }

        if(dp[left][right]!=-1)
        {
            return dp[left][right];
        }

        int res = INT_MAX;
        // take any value from left to right and call other left and right part recursively
        for(int i =left;i <= right; i++ )
        {
            // we will take min of max
            // for particular i     Case 1: helper(left, i-1)
            //                      Case 2: helper(i+1, right)
            res = min(res, i+max(helper(left, i-1),helper(i+1, right)));
        }

        dp[left][right] = res;

        return res;


    }
    int getMoneyAmount(int n) 
    {
        dp.resize(n+1, vector<int>(n+1,-1));
        return helper(1, n);

    }
};