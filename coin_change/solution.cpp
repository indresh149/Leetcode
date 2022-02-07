class Solution {
public:
    int dp[10001];
    int help(int amount,vector<int>&coins){
        if(amount==0)return 0;
        int ans=INT_MAX/2;
        if(dp[amount]!=-1)return dp[amount];
        for(int i=0;i<coins.size();i++)
        {
            if(amount>=coins[i])
            {
                int op=1+help(amount - coins[i],coins);
                ans=min(ans,op);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
          memset(dp,-1,sizeof dp);
        int ans= help(amount,coins);
        if(ans==INT_MAX/2)return -1;
        return ans;
    }
};