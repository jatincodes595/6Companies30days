#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> q;
        // just try to maintain a incresing order from front to rear
        // so taht we can pop maximum element from the front
        for(int i=0;i<k-1;i++)
        {
            while(!q.empty() && arr[q.back()]<arr[i])
            q.pop_back();
            
            q.push_back(i);
        }
        vector<int> ans;
        for(int i=k-1;i<n;i++)
        {
             if(q.front()==(i-k))
            q.pop_front();
             while(!q.empty() && arr[q.back()]<arr[i])
            q.pop_back();
            q.push_back(i);
            
            ans.push_back(arr[q.front()]);
           
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends