class Solution {
public:
    int canShip(int mid,vector<int>& weights,int D)
    {
        int n=weights.size();
        int days=1;
        int total=0;
        for(int i=0;i<n;i++)
        {
            if(total+weights[i]>mid)
            {
                days++;
                total=weights[i];
                if(days>D)
                    return false;
            }
            else
            {
                total+=weights[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int D)
    {
        int l=1;
        for(int i=0;i<weights.size();i++)
        {
            l=max(l,weights[i]);
        }
        
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=r;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(canShip(mid,weights,D))
            {
                ans=mid;
                r=mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};