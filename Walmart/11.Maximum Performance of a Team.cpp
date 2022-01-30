class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int,int>>result;
        // min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i < speed.size(); i++)
            result.push_back({efficiency[i],speed[i]});
        // we sort on the basis of efficiency
        sort(result.begin(),result.end());
        // sum -> total speed
        long long ans = 0, sum = 0, mod = 1e9+7;   
        for(int i = result.size()-1; i >= 0; i--)
        {
             // if pq size more than or equal k then pop top element and sub from sum
            // we are popping because in the next step we are pushing then the size will become K
            if(pq.size()>=k)
            {
                sum -= pq.top();
                pq.pop();
            }
            // we push only the speed
            pq.push(result[i].second);
            sum += result[i].second;
           
            // eff will always be min because we sorted in increasing order
            //cout<<sum*result[i].first<<"\n";
            ans = max(ans,sum*result[i].first);
        }
        return ans%mod;
    }
};