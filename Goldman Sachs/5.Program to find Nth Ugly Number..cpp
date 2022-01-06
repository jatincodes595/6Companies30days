#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	
//	https://leetcode.com/problems/ugly-number-ii/discuss/719374/0704-or-Ugly-Number-II-or-O(N)-C%2B%2B-Solution
	ull getNthUglyNo(int n) 
	{
	     vector <ull> results (1,1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            // 3no me se minimum lo jis se koi leave naa ho
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            // neeche ki 3 conditions is liye hai jis se ki repeat naa ho kuch
            if (results.back() == results[i] * 2) i++;
            if (results.back() == results[j] * 3) j++;
            if (results.back() == results[k] * 5) k++;
        }
        return results.back();
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends