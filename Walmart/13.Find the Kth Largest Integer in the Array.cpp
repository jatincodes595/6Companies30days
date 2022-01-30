struct comp
{
    bool operator()(string a,string b)
    {
        if(a.size()<b.size())
        {
            return false;
        } else if(a.size()>b.size())
        {
            return true;
        }
        for(int i=0;a[i];i++)
        {
            if(a[i]>b[i])
            {
                return true;
            }
            else if(a[i]<b[i])
                return false;
        }
        return true;
    }
};


class Solution 
{
public:
    
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        // min heap
        priority_queue<string,vector<string>,comp> q;
        for(int i=0;i<nums.size();i++)
        {
            q.push(nums[i]);
            if(q.size()>k)
            {
                q.pop();
            }
        }
        return q.top();
    }
};