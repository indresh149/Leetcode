class Solution {
public:
    int findway(vector<int>&nums,int target,int currsum,vector<int>&dp){
        if(currsum > target){
            return 0;
        }
        if(currsum == target){
            return 1;
        }
        
        if(dp[currsum] != -1){
            return dp[currsum];
        }
        
        int ans = 0;
        for(int i=0;i < nums.size();i++){
            ans += findway(nums,target,currsum + nums[i],dp);
        }
        return dp[currsum] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp;
        dp.assign(1001,-1);
        int currsum = 0;
            return findway(nums,target,currsum,dp);
    }
};