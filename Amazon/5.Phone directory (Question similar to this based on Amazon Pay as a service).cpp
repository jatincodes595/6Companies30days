// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    struct Node
    {
        struct Node *children[26];
        vector<int> indexes;
        int isLeaf;
    };
    void insert(Node *root,string s,int ind)
    {
        int i,j,temp;
        Node *p;
        for(i=0;i<s.size();i++)
        {
            temp=s[i]-97;
            if(root->children[temp]!=NULL)
            {
                 (root->children[temp]->indexes).push_back(ind);
                 root=root->children[temp];
            }
            else
            {
                p=new Node();
                for(j=0;j<26;j++)
                    p->children[j]=NULL;
                p->isLeaf=0;
                p->indexes.push_back(ind);
                root->children[temp]=p;
                root=p;
            }
        }
        root->isLeaf=1;
    }
    public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
        vector<vector<string>> ans;
        Node *root=new Node();
        for(int i=0;i<n;i++)
        {
            insert(root,contact[i],i);
        }
        int flag=1;
        for(int i=0;s[i];i++)
        {
            if(root->children[s[i]-'a'] != NULL && flag==1)
            {
                    vector<string> mid;
                    set<string> st;
                    vector<int> a=root->children[s[i]-'a']->indexes;
                    for(int j=0;j<a.size();j++)
                    {
                        //cout<<j<<" ";
                        st.insert(contact[a[j]]);
                    }
                    //cout<<"\n";
                    for(auto x:st)
                    {
                        mid.push_back(x);
                    }
                    ans.push_back(mid);
                root=root->children[s[i]-'a'];
            }
            else
            {
                flag=0;
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends