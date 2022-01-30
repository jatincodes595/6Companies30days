class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        // the test case which is important otherwise it will pass
        if(dividend==-2147483648 && divisor==-1)
            return 2147483647;
        long quotient;
        quotient = dividend/divisor;
        return quotient;
        
    }
};