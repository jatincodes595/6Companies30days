 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int sum=0;
        int le=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==s)
            {
                ans.push_back(le+1);
                ans.push_back(i+1);
                break;
                
            }
            else
            {
                while(sum>s)
                {
                    sum-=arr[le];
                    le++;
                    if(sum==s)
                    {
                        ans.push_back(le+1);
                        ans.push_back(i+1);
                        break;
                        
                    }
                }
            }
            if(sum==s)
            break;
        }
        if(ans.size()==2)
        return ans;
        else
        {
            ans.push_back(-1);
            return ans;
        }
    }
};