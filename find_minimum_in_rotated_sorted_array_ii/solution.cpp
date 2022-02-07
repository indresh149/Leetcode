class Solution {
public:
    int findMin(vector<int>& nums) {
        int a=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<a)
            {
                a=nums[i];
            }
        }
        return a;
    }
};