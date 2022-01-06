class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        string ans;
        string mid;
        
        int n1=str1.size();
        int n2=str2.size();
        
        for(int i=0,j=0;i<n1,j<n2;i++,j++)
        {
            if(str1[i]==str2[j])
            {
                mid+=str1[i];
            }
            else
                break;
            if(n1%(mid.size())==0 && n2%(mid.size())==0)
            {
                string s1=mid;
                
                for(int k=2;k<=(n1/mid.size());k++)
                {
                    s1+=mid;
                }
                
                string s2=mid;
                
                for(int k=2;k<=(n2/mid.size());k++)
                {
                    s2+=mid;
                }
                if(s1==str1 && s2==str2)
                {
                    ans=mid;
                }
            }
        }
        return ans;
    }
};
