class Solution {
public:
    int climbStairs(int n ) {
if (n == 1)
return 1;
if (n == 2)
return 2;
int dp[50] = {0, 1, 2};
for (int i = 3; i <= n; i++)
dp[i] = dp[i - 1] + dp[i - 2];
return dp[n];
}
};