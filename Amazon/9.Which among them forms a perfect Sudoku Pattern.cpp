// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> board)
    {
         // used1 is used to keep update of every ith row
        // used2 is used to keep update of evey jth row
        // used3 is used to keep update of every block {as there are 8 blocks..so for each block it update values..}
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
        {
            for(int j = 0; j < board[i].size(); ++ j)
            {
                if(board[i][j] !=0)
                {
                    // num--> 0-8 
                    // k values represent value of block 0 to 8th block
                    int num = board[i][j]- 1, k = i / 3 * 3 + j / 3;
                    // if there is any value which was previously updated then it is wrong sudoku
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return 0;
                    // else update the values
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
                
        }
            
        
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends