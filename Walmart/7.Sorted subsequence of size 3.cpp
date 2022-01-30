/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
  // tried it to do it in O(1) space but that gives the 3 nos but not always the first triplet
    vector<int> find3Numbers(vector<int> arr, int n) 
    {
        
        int min = 0;
        vector<int> smaller(n);
     
        // first entry will always be -1
        smaller[0] = -1;
        for (int i = 1; i < n; i++) 
        {
            if (arr[i] <= arr[min]) 
            {
                min = i;
                smaller[i] = -1;
            }
            else
                smaller[i] = min;
        }
     
        vector<int> greater(n);
        int max = n - 1;
        // last entry will always be -1
        greater[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) 
        {
            // that means the no is greater than all nos on right 
            // therefore put -1
            if (arr[i] >= arr[max]) 
            {
                max = i;
                greater[i] = -1;
            }
            else
                greater[i] = max;
        }
    
        for (int i = 0; i < n; i++) 
        {
            
            if (smaller[i] != -1 && greater[i] != -1)  /// that means the current no is middle of two nos
            {
                return {arr[smaller[i]],arr[i],arr[greater[i]]};
            }
        }
        return {}; 
    }
};