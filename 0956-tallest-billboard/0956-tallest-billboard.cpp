class Solution {
public:
    int solve(int i,int diff,vector<int>&rods,int half,vector<vector<int>>&dp)
    {
        if(diff>half or diff<-1*(half))return -1e9;
        if(i==rods.size())
        {
            if(diff==0)return 0;
            else return -1e9;
        }
        
        if(dp[i][diff+half]!=-1)return dp[i][diff+half];
        int ans=-1e9;
        //not take in any set
        ans=max(ans,solve(i+1,diff,rods,half,dp));

        //take in set 1
        ans=max(ans,rods[i]+solve(i+1,diff+rods[i],rods,half,dp));

        //take in set 2
        ans=max(ans,solve(i+1,diff-rods[i],rods,half,dp));
        return dp[i][diff+half]=ans;

    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int total=accumulate(rods.begin(),rods.end(),0);
        int half=total/2;
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        int ans= solve(0,0,rods,half,dp);
        if(ans<0)ans=0;
        return ans;
        
    }
};