class Solution{
    public:
    string amendSentence (string s)
    {
        string ans;
        for(int i=0;s[i];i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                if(i!=0)
                ans+=' ';
                ans+=((s[i]-'A')+'a');
                
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};