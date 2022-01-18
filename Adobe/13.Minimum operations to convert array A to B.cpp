class Solution {
  public:
  // B array is given in sorted order
    int minInsAndDel(int A[], int B[], int N, int M)
    {
        vector<int> lis;
        unordered_set<int> set;
        for(int i = 0 ; i < M; i++)
        {
            set.insert(B[i]);
        }
        
        for(int i = 0; i < N; i++)
        {
            if(set.find(A[i]) !=set.end())
            {
                auto it = lower_bound(lis.begin(), lis.end(), A[i]);
                if(it == lis.end()) // means A is in order of B ..therefore push element at back
                {
                    lis.push_back(A[i]);
                }
                else /// else just replace with the element which is greater or equal to that element
                    *it = A[i];
            }
        }
        // lis is the longest vector of elemts in both the array 
        return N+M- 2* lis.size();
    }
};