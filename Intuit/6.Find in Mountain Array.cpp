
// Although this question is generally based on binary search
// But the thing which i noticed that all the interactive problems
// can be solved using binary search
// for more questions on interactive refer codeforces and codechef
class Solution {
public:
    /// this is a simple interactive problem
    // as log2(10^4) * 3 = 40 which is less than 100 ...so this solution will work
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();
        int max_idx = 0;
        int lo=0, hi = n-1;
        // first finding the peak point in the array
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                lo = mid+1;
            else
                hi = mid;
        }
        max_idx = lo;
        // now finding the elemnt in the left array
        lo =0, hi = max_idx;
        
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)<target)
                lo = mid+1;
            else if(mountainArr.get(mid)==target)
                return mid;
            else
                hi = mid-1;
        }
        // if element not found in left array we will find in right array
        lo =max_idx+1, hi = n-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)>target)
                lo = mid+1;
            else if(mountainArr.get(mid)==target)
                return mid;
            else
                hi = mid-1;
        }
        // if elemet not found return -1
        return -1;
    }
};