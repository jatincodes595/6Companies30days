/* You are required to complete this function
which return the required missing number
if present else return -1*/
long long sto(string s)
{
    long long x=0;
    for(int i=0;i<s.size();i++)
      x=x*10+s[i]-'0';
    return x;
}

int missingNumber(const string& s)
{
    int n=s.size();
    for(int len=1;len<=6;len++)
    {
       string temp="";
       int l=len,i=0;
       while(i<s.size() && l--)
        temp+=s[i++];
       long long prev=sto(temp),count=0,j=i,miss,flag=0;
       temp="";
       while(j<s.size())
       {
               temp+=s[j++];
               long long val=sto(temp);
               if(prev+1==val)
               {
                   prev=val;
                   temp="";
               }
               else if(prev+2==val)
                    {
                        count++;
                        miss=prev+1;
                        prev=val;
                        temp="";
                    }
                    else if(prev<val)
                    {
                        flag=1;
                        break;
                    }
                           
        }
        // count is used to find no of missed elemts and flag=1 represent that gap is more than 2
        if(count==1 && flag==0)
         return miss;
    }
    return -1;
}