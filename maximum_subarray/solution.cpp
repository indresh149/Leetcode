class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start=INT_MIN,end=0;
        for(int i=0;i<nums.size();i++)
        {
            end+=nums[i];
            if (start < end)
            start = end;
 
        if (end < 0)
            end = 0;
    }
    return start;
        
    }
};