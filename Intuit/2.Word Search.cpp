class Solution {
public:
    bool solve(vector<vector<char>>& board,string word,int i,int j,int k)
    {
        if(k==word.size())
        {
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j] != word[k])
        {
            return false;
        }
       
        board[i][j]='0';
        bool res= solve(board,word,i,j+1,k+1) || solve(board,word,i+1,j,k+1) || solve(board,word,i-1,j,k+1) ||solve(board,word,i,j-1,k+1);
        board[i][j]=word[k];
        return res;
    }
 
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
               if(board[i][j]==word[0] && solve(board,word,i,j,0))
               {
                   return true;
               }
            }
        }
        return false;
    }
};