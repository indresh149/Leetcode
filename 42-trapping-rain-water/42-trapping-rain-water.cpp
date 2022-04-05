class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <=2 ) return 0;
        int maxl = height[0],maxr = height[n-1];
        int l = 1,r =n-2,ans =0;
        while(l <= r)
        {
            if(maxl < maxr)
            {
                if(height[l] > maxl)
                {
                    maxl = height[l];
                }
                else
                {
                    ans += maxl - height[l];
                }
                l+=1;
            }
            else
            {
               if(height[r] > maxr)
               {
                   maxr = height[r];
               }
                else
                {
                    ans += maxr - height[r];
                }
                r-=1;
            }
        }
        return ans;
    }
};