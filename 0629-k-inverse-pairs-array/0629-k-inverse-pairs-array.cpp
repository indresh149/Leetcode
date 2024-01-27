class Solution {
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int K) {
        int dp[1001][1001] = {1};
        for(int i = 1;i<=n;i++)
        {
            for(int j=0;j<=K;j++)
            {
                for(int k=0;k<= min(j,i-1);k++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k])%1000000007;
                }
            }
        }
        return dp[n][K];
    }
};