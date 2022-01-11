class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    
    
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        vector<vector<int>> ans1;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int le=j+1,ri=n-1;
                while(le<ri)
                {
                    if((arr[i]+arr[j]+arr[le]+arr[ri])==k)
                    {
                        vector<int> ans={arr[i],arr[j],arr[le],arr[ri]};
                        ans1.push_back(ans);
                        le++;
                        ri--;
                    }
                    else if((arr[i]+arr[j]+arr[le]+arr[ri])<k)
                    {
                        le++;
                    }
                    else if((arr[i]+arr[j]+arr[le]+arr[ri])>k)
                    {
                        ri--;
                    }
                }
            }
        }
        return ans1;
    }
};