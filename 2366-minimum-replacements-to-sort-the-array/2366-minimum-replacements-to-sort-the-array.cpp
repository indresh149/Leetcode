class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long ans =0;
        int n = nums.size();
        int prev = nums[n-1];
        for(int i=n-2;i >= 0;i--){
            int noofDeletions = nums[i]/prev;
            if(nums[i]%prev != 0){
                noofDeletions++;
            }
            if((nums[i])%prev != 0){
                prev = nums[i]/noofDeletions;
            }
            ans += noofDeletions-1;
        }
        return ans;
        
    }
};