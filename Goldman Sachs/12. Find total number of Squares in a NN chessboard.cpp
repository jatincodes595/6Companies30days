
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    // it is just sum of squares of nos from 1 to n
    // 1^2 + 2^2 + 3^2 + --------- + n^2
    
    // 1 x 1: 8 * 8 = 64 squares.
    // 2 x 2: 7 * 7 = 49 squares.
    // 3 x 3: 6 * 6 = 36 squares.
    // 4 x 4: 5 * 5 = 25 squares.
    // 5 x 5: 4 * 4 = 16 squares.
    // 6 x 6: 3 * 3 = 9 squares.
    // 7 x 7: 2 * 2 = 4 squares.
    // 8 x 8: 1 * 1 = 1 square.
    long long squaresInChessBoard(long long n) 
    {
        return (n * (n + 1) / 2) * (2 * n + 1) / 3;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends