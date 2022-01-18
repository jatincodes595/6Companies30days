class Solution
{
  public:
  const int MOD = 1e9+7;
  vector<vector<int> > dp;
    long long solve(int N, int K, int i, int j) 
    {
        
        if (i == N) 
        {
            return 1;
        }
        if (dp[i][j] != -1) 
        {
            return dp[i][j]%MOD;
        }
        
        long long words = 0;
        if (j > 0) 
        {
            // first take vowels and decrease the no of used vowels by 1
            words = 5*solve(N, K, i+1, j-1);
            words %= MOD;
            // if using consonant then no of usd vowels will again become K
            words += 21*solve(N, K, i+1, K);
        } 
        else // if already k vowels have come toether then start with consonant and no of used vowels = k
        {
            words = 21*solve(N, K, i+1, K);
        }
        
        words %= MOD;
        return dp[i][j] = words%MOD;
    }
    
    int kvowelwords(int N, int K) 
    {
        // Write Your Code here
        dp.clear();
        dp.resize(N+1, vector<int>(K+1, -1));
        return solve(N, K, 0, K);
    }
};