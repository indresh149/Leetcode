class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int end=nums.size()-1;
        while(s<=end)
        {
            int mid=(s+end)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                 s=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return end+1;
    }
};