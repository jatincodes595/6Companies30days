//Given two library versions of an executable: 
//for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. 
//Find out which one is more recent? Strings can be empty also.


#include<bits/stdc++.h>
using namespace std;

int main()
{
    // take 2 versions to compare
   string ver1,ver2;
   cin>>ver1>>ver2;
   if(ver1==ver2)
   cout<<ver1<<"\n";
   
   int i=0,j=0;
   string ans;
   while(i<ver1.size() || j<ver2.size())
   {
       int val1=0;
       while(i<ver1.size() && ver1[i]!='.')
       {
           val1=val1*10+(ver1[i]-'0');
           i++;
       }
       i++;
       //cout<<val1<<"\n";
       int val2=0;
       while(j<ver2.size() && ver2[j]!='.')
       {
           val2=val2*10+(ver2[j]-'0');
           j++;
       }
       j++;
       //cout<<val2<<"\n";
       if(val1==val2)
       continue;
       if(val1>val2)
       {
           ans=ver1;
           break;
       }
       else
       {
           ans=ver2;
           break;
       }
       
   }
   // output the version which is more recent
   cout<<ans<<"\n";
}