#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    // best method is to  use queue otherwise it will become hard to code
    vector<string> ans;
    queue<string> q;
    q.push("1");
    while(N--)
    {
        auto x=q.front();
        q.pop();
        ans.push_back(x);
        q.push(x+'0');
        q.push(x+'1');
    }
    return ans;
	// Your code here
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends