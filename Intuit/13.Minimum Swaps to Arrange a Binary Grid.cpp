//1st Code using greedy approach

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n=grid.size(),res=0;
        vector<int>a(n);
        for(int i=0 ; i<n ; i++)              //finding the no of continous zeroes at the end of each row.
        {
            int j=n-1,cnt=0;
            while(j>=0 and grid[i][j]==0) 
            {
                cnt++;
                j--;
            }
            a[i]=cnt;
        }
        for(int i=0 ; i<n ; i++)               //for calculating the swaps count or sorting the array decreasing.
        {
            if(a[i]<n-1-i)// this means that no should go down to another position
            {
                int j=i;
                while(j<n and a[j]<n-1-i) // finding that no that will fit into that postion a[j]>=(n-1-i)
                    j++;
                if(j==n) 
                    return -1;
                while(i<j) // now swap to get that to its correct place
                {
                    swap(a[j],a[j-1]);
                    res++;
                    j--;
                }
            }
        }
        return res;
    }
};



//2nd code using recursion
class Solution {
public:
    int n;
    vector<vector<int>> grid;
    const int MAX_VAL = 100000; 
    int recur(int i)
    {
    
        if(i == n) return 0;
          
        //greedily choosing closer ones
        
        int req = n-1-i;
        for(int x=i;x<n;++x)
        {
            int curr = 0;
            for(int j=n-1;j>=0 && grid[x][j]==0;--j) 
                ++curr;
            if(curr>=req)
            {
                
                for(int xd=x;xd>i;--xd)
                {
                    swap(grid[xd],grid[xd-1]);
                }
                
                return x-i + recur(i+1);
            }
        }
       
        return MAX_VAL;
    }
    
    int minSwaps(vector<vector<int>>& grid) 
    {
        n = grid.size();
        this->grid = grid;
        int val = recur(0);
        return val >= MAX_VAL ? -1 : val;
    }
};