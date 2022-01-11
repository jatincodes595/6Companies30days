class Solution{
public:
    
    int minSteps(int D)
    {
    
        int sum = 1, step = 1;
        
        while(true)
        {
            if(sum==D)
            return step;
            // means sum-2*i that is why we need sum-D as even
            // beacuse jo initailly +i kiya tha abb jab us step ko negative me lena hai to
            // 2 times -i karna padega
            if(sum>D && (sum-D)%2==0)
            return step;
            
            step++;
            sum+=step;
            
        }
    }
   
};