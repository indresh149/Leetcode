class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i1, int i2, int prev, vector<int>&a1, vector<int>&a2)
    {
        if(i1==a1.size())
        {
            return 0;
        }
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        int notpick=1e9,pick=1e9;
        if(a1[i1]>prev)
        {
            notpick=solve(i1+1,i2,a1[i1],a1,a2);
        }
        i2=upper_bound(a2.begin(),a2.end(),prev)-a2.begin();
         if(i2<a2.size())
         { pick=1+solve(i1+1,i2+1,a2[i2],a1,a2);
         }
          return  dp[i1][i2]=min(notpick,pick);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int n1=arr1.size(),n2=arr2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        if(solve(0,0,-1,arr1,arr2)>n1)
        { return -1;}
        return solve(0,0,-1,arr1,arr2);
    }
};