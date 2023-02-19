class Solution {
    public int reverse(int x) {
        int num=x;
        int n=0;
        if(x<0)
         x=0-x;
        while(x>0)
        {
            if(900000000<n)
                return 0;
            n=(n*10)+(x%10);
            x/=10;
            if(n<0)
            return 0;
        }
         
        if(num<0)
        {
            return n*(-1);
        }
       
        return n;
    }
}