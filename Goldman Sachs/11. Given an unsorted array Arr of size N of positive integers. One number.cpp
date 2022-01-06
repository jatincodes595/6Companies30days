#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        int no1,no2;
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==2)
            {
                no1=i;
            }
            else if(mp[i]==0)
            {
                no2=i;
            }
        }
        static int ans[2];
        ans[0]=no1;
        ans[1]=no2;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends