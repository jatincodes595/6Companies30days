// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    
    void solve(string s,int left,int right)
    {
        if(left==0 && right==0)
        {
            ans.push_back(s);
            return;
        }
        // if left becomes more than right then definately the balanced string will not be formed
        if(left>right)
        return;
        if(left>=1)
        solve(s+'(',left-1,right);
        if(right>=1)
        solve(s+')',left,right-1);
    }
    vector<string> AllParenthesis(int n) 
    {
        ans.clear();
        string s;
        solve(s,n,n);
        return ans;
    }
};