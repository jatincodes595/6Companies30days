//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //Function to find list of all words possible by pressing given numbers.
    vector<string> ans;
    
    void solve(int a[],int i,int n,string s)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        
        for(int j=0;j<keypad[a[i]].size();j++)
        {
            solve(a,i+1,n,s+keypad[a[i]][j]);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        string s;
        solve(a,0,N,s);
        //sort(ans.begin(),ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends