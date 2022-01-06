#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans;
        while (n > 0) {
            // Find remainder
            int rem = n % 26;
             // start filling from last   
            // If remainder is 0, then a 'Z' must be there in output
            if (rem == 0) {
                ans+='Z';
                n = (n / 26) - 1;
            }
            else // If remainder is non-zero
            {
                ans+=((rem - 1) + 'A');
                n = n / 26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends