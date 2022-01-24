class Solution {
public:
    // it is same as Allocate minimum number of pages
    bool isPossible(vector<int> arr, int n, int m, int curr_min)
    {
        
        int studentsRequired = 1;
        int curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
    
            
            if (curr_sum + arr[i] > curr_min)
            {
                studentsRequired++;
    
                curr_sum = arr[i];
    
                
                if (studentsRequired > m)
                    return false;
            }
            else
                curr_sum += arr[i];
        }
        return true;
    }
    int splitArray(vector<int>& arr, int m) 
    {
        int n=arr.size();
   
        int sum = 0;
        int start=0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            start=max(start,arr[i]);
        }
        

        int end = sum;
        int result;

        while (start <= end)
        {
            int mid = start + (end-start) / 2;
            if (isPossible(arr, n, m, mid))
            {
                
                result =mid;
    
              
                end = mid - 1;
            }
    
            else

                start = mid + 1;
        }

        
        return result;
    }
};