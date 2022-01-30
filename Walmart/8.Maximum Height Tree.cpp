class Solution{
public:
    // eq is (x*(x+1))/2=N
    // just calculate value of x
    int height(int N)
    {
        double x=(double)sqrt(1+4*2*N);
        x--;
        x=x/2;
        return floor(x);
    }
};