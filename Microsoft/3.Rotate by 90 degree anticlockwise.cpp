
#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
 
// first do transpose and the just reversing the columns would be easy task instead of doing it with only one function
void reverseColumns(vector<vector<int> >& arr)
{
    // swap first row with last row and so on
    int n=arr.size();
    for (int i = 0; i < n; i++)
        for (int j = 0, k = n - 1; j < k; j++, k--)
            swap(arr[j][i], arr[k][i]);
            
            // printMatrix(arr);
}

// Function for do transpose of matrix
void transpose(vector<vector<int> >& arr)
{
    int n=arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            swap(arr[i][j], arr[j][i]);
            // printMatrix(arr);
}
void rotate(vector<vector<int> >& matrix)
{
     transpose(matrix);
    reverseColumns(matrix);
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
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends