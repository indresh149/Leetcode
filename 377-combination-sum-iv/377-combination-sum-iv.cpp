class Solution {
public:
    int f(vector<int> &num, int tar,vector<int> &dp){
        if(tar < 0) return 0;
        
        if(tar == 0) return 1;
        
        if(dp[tar] != -1) return dp[tar];
        int ans = 0;
        for(int i=0;i<num.size();i++){
            ans += f(num,tar - num[i],dp);
        }
        return dp[tar] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
       return f(nums,target,dp); 
    }
};