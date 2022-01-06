
 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string arr)
    {
        // min_avail represents the minimum number which is
    	// still available for inserting in the output vector.
    	// pos_of_I keeps track of the most recent index
    	// where 'I' was encountered w.r.t the output vector
    	int min_avail = 1, pos_of_I = 0;
    
    	//vector to store the output
    	vector<int>v;
    
    	// cover the base cases
    	if (arr[0]=='I')
    	{
    	    // if we need to increase value then best option is to use the last 'I' th pos
    		v.push_back(1);
    		v.push_back(2);
    		min_avail = 3;
    		pos_of_I = 1;
    	}
    	else
    	{
    	    // we took posof_I=0 beacuse if 'D' comes we can increase the previous values 
    		v.push_back(2);
    		v.push_back(1);
    		min_avail = 3;
    		pos_of_I = 0;
    	}
    
    	// Traverse rest of the input
    	for (int i=1; i<arr.length(); i++)
    	{
    		if (arr[i]=='I')
    		{
    			v.push_back(min_avail);
    			min_avail++;
    			pos_of_I = i+1;// pointing to last 'I' th pos ..so that if 'D' comes it can be increased
    		}
    		else
    		{
    		    	// i th index will always point to last element of v
    		    	// so push that element agaian ..so that its previous elemets can be increased
    			v.push_back(v[i]);
    		
    			for (int j=pos_of_I; j<=i; j++)
                {
                  v[j]++;
                }
    			min_avail++;
    		}
    	}
    
        string ans;
    	for(int i=0;i<v.size();i++)
    	{
    	    ans+=('0'+v[i]);
    	}
    	return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends