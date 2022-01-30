class Solution{
    public:
    //You need to complete this fucntion
    long long power(int N,int R)
    {
      long long result = 1;
        while (R > 0) 
        {
            if (R % 2 == 0) 
            {
                // this (long long) is most imp as N is int and N*N can exceed range 
                //of int so typecast it int long long so that it remians in range and after taking mod it comes in range of int
                N = (long long)N * N%mod;
                R = R / 2;
            }
            else 
            {
                result = (long long)result * N%mod;
                R = R - 1;
            }
        }
        return result%mod;
        
    }

};