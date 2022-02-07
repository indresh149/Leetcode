class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
         int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]== pivot)
            {
                count++;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
               v.push_back(nums[i]);
            }
        }
        while(count>0)
        {
            v.push_back(pivot);
            count--;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]> pivot)
            {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};