
 // } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
        int total=r*c;
        vector<int> ans;
    int left=0,right=c-1;
    int up=0,down=r-1;
    while(total)
    {
        for(int i=left;i<=right;i++)
        {
            ans.push_back(a[up][i]);
            total--;
        }
        if(total==0)
        break;
        for(int i=up+1;i<=down-1;i++)
        {
            ans.push_back(a[i][right]);
            total--;
        }
        if(total==0)
        break;
        for(int i=right;i>=left;i--)
        {
            ans.push_back(a[down][i]);
            total--;
        }
        if(total==0)
        break;
        for(int i=down-1;i>=up+1;i--)
        {
            ans.push_back(a[i][left]);
            total--;
        }
        if(total==0)
        break;
        left++;
        right--;
        down--;
        up++;
    }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends