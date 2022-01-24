class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string max;
    void Kswaps(string str, int k, int ctr)
    {
        // return if no swaps left
        if (k == 0)
            return;
    
        int n = str.length();
    

        // search this maximum among the rest
        for (int j = ctr+1; j < n; j++) 
        {
            // If digit equals maxm swap
            // the digit with current
            // digit and recurse for the rest
            if (str[j] >str[ctr]) 
            {
                // swap str[ctr] with str[j]
                swap(str[ctr], str[j]);
    
                // If current num is more than
                // maximum so far
                if (str.compare(max) > 0)
                    max = str;
    
                // recurse other swaps after cur
                Kswaps(str, k-1, ctr + 1);
    
                // Backtrack
                swap(str[ctr], str[j]);
            }
        }
    }
  
    string findMaximumNum(string str, int k)
    {
        max=str;
        Kswaps(str,k,0);
        return max;
    }
};