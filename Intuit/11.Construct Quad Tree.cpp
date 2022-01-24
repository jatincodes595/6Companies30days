class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int l = 1, r = 1e9;
        int ans=1e9;
        while (l < r) 
        {
            int m = l+(r-l)/2;
            int total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total<=H)
            {
                ans=m;
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    
    }
};