class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int> mp;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
        }
        string ans;
        for(auto x:mp)
        {
            if(x.second==maxi)
            {
                ans=x.first;
                break;
            }
        }
        return {ans,to_string(maxi)};
        
        
    }
};