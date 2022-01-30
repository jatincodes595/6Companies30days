class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        vector<int> a,b;
        int cnt=1;
        int z=colors.size();
        for(int i=1;i<z;i++)
        {
            if(colors[i-1]==colors[i])
            {
                cnt++;
            }
            else
            {
                if(colors[i-1]=='A')
                {
                    a.push_back(cnt);
                }
                else
                {
                    b.push_back(cnt);
                }
                cnt=1;
            }
        }
        if(colors[z-1]=='A')
             a.push_back(cnt);
        else
             b.push_back(cnt);
        int i=0,j=0;
        int n=a.size(),m=b.size();
        bool flag=0;
        while(1)
        {
            if(flag==0)
            {
                for(;i<n;i++)
                {
                    if(a[i]>=3)
                    {
                        a[i]--;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }
            else
            {
                for(;j<m;j++)
                {
                    if(b[j]>=3)
                    {
                        b[j]--;
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
        }
        if(flag==1)
            return true;
        else
            return false;
        
    }
};