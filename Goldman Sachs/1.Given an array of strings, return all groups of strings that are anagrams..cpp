//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& s) 
{
    vector<string> s1=s;
    vector<vector<string>> ans;
    vector<int> vis(s.size());
    for(int i=0;i<s1.size();i++)
    {
        sort(s1[i].begin(),s1[i].end());
    }
    // for(int i=0;i<s1.size();i++)
    // {
    //     cout<<s1[i]<<"\n";
    // }
    for(int i=0;i<s1.size();i++)
    {
        if(vis[i]==0)
        {
            vector<string> part;
           for(int j=i;j<s1.size();j++)
            {
                if(s1[i]==s1[j])
                {
                    vis[j]=1;
                    part.push_back(s[j]);
                }
            }
            ans.push_back(part);
        }
    }
    return ans;
    // Your Code Here
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends