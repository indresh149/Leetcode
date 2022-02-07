class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        int i2=0,i3=0,i5=0;
        int nml2=2;
        int nml3=3;
        int nml5=5;
        int next_ugly=1;
        
        ugly[0]=1;
        for(int i=1;i<n;i++)
        {
            next_ugly=min(nml2,min(nml3,nml5));
            ugly[i]=next_ugly;
            if(next_ugly==nml2)
            {
                i2=i2+1;
                nml2=ugly[i2]*2;
            }
            if(next_ugly==nml3)
            {
                i3=i3+1;
                nml3=ugly[i3]*3;
            }
            if(next_ugly==nml5)
            {
                i5=i5+1;
                nml5=ugly[i5]*5;
              }
        }
        return next_ugly;
    }
};