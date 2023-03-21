class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long r = 0;
       long long c = 0;
        
        int n = nums.size();
        
        
        for(int i = 0; i< n ; i++)
        {
            if(nums[i] == 0) 
            {
                c++;
            }
            else
            {
                r += (c* (c+1))/2; c = 0;
            }
        }
        
        r += (c*(c+1))/2;
        return r;
    }
};