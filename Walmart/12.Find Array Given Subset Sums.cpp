class Solution {
public:
    //// this algo is iterative version of divide and conquer
    // try to dry run this code on paper so that you can get the idea wisely
    vector<int> recoverArray(int n, vector<int>& sums) 
    {
        // first sort the array
        sort(sums.begin(), sums.end()); 
        
        vector<int> ans; 
        while (n--) 
        {
            // either you take the diff of first two elemts or last 2 elemts 
            // so we just need to decide wether -diff or +diff will be in the main array
            int diff = sums[1] - sums[0]; 
            unordered_map<int, int> freq; 
            vector<int> ss0, ss1; 
            bool on = false; // this will decide whether diff will be neg or pos
            // we just need to make to array ss0 and ss1 so that one array can be converted to another array 
            // by just adding or subtracting diff  to every value in one of the array i.e. ss0 or ss1
            for (auto& x : sums) 
            {
                if (freq[x]==0) 
                {
                    ss0.push_back(x); 
                    freq[x+diff]++; 
                    // if x comes for the first time with 0 freq that means the diff is pos 
                    // beacuse if prev + diff are able to make the 0 value then it is confirmed the array contains a -ve no
                    if (x == 0) on = true; 
                } 
                else 
                {
                    ss1.push_back(x); 
                    freq[x]--; 
                }
            }
            if (on) 
            {
    // here +diff and ss0 represent if we subtract diff to every value of ss0 array then it will give ss1 array
                ans.push_back(diff); 
                sums = ss0; 
                
            } 
            else 
            {
    // here -diff and ss1 represent if we add diff to every value of ss1 array then it will give ss0 array
                ans.push_back(-diff); 
                sums = ss1; 
            }
        }
        return ans; 
    }
};
