#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n),vis(n),vis1(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            vis[i]=1;
        }

    }
    ll time=0;
    for(ll i=0;i<n;i++)
    {
      if(a[i]==1)
      {
          ll j=i+1;
          ll t1=INT_MAX;
          for(;j<n;j++)
          {
            if(vis[j]==0)
            {
              t1=abs(j-i);
              break;
            }
          }
          ll t2=INT_MAX;
          ll k=i-1;
          for(;k>=0;k--)
          {
            if(vis[k]==0)
            {
              t2=abs(k-i);
              break;
            }
          }
          if(t1>t2)
          {
            vis[k]=1;
            vis1[k]=1;
            time+=t2;
          }
          else
          {
            vis[j]=1;
            vis1[j]=1;
            time+=t1;
          }
      }
    }
    for(auto x:vis1)
    cout<<x<<" ";
    cout<<"\n";
    cout<<time<<"\n";
}
