class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int size=INT_MAX;
        int sum=0;
        int st=0;
        sum+=nums[0];
        if(sum>=target)
        {
            size=1;
            return 1;
        }
            
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>=target)
            {
                
                while(sum>=target)
                {
                    size=min(size,i-st+1);
                    //cout<<size<<"\n";
                    sum-=nums[st];
                    st++;
                }
            }
        }
        if(INT_MAX==size)
            return 0;
        return size;
    }
};