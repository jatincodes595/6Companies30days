class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        int ans=0;
        int n=str.size();
        int i=0;
        int mul=1;
        // checking whether the no is neg or not
        if(str[i]=='-')
        {
            mul=-1;
            i++;
        }
        
        for(;str[i];i++)
        {
            int x=str[i]-'0';
            if(x>=0 && x<=9)
            {
                ans=ans*10+x;
            }
            else
            return -1;
        }
        return mul*ans;
    }
};