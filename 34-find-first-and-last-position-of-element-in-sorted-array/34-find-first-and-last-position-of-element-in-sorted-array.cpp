class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            vector<int>v;
        int i=0,j=nums.size(),mid=(i+j)/2,k=-1,mid2=-1;
        
         while (i < j) {
        mid = (i + j) / 2;
        if (nums[mid] >= target)
            j = mid;
        else
            i = mid + 1;
       }
       k = i;
       i = 0, j = nums.size();
       while (i < j) {
        mid = (i + j) / 2;
        if (nums[mid] > target)
            j = mid;
        else
            i = mid + 1;
    }
    mid2 = i;
    return k == mid2 ? vector<int> {-1,-1} : vector<int> {k,mid2-1};
}
        
    
       
};