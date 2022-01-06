#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
      string ans;
      int cnt=1;
      for(int i=0;i<src.size()-1;i++)
      {
          if(src[i]==src[i+1])
          {
              cnt++;
          }
          else
          {
              ans+=src[i];
              ans+=('0'+cnt);
              cnt=1;
          }
      }
      ans+=src[src.size()-1];
      ans+=('0'+cnt);
      return ans;
              
}     
 
