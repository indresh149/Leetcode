class Solution {
public:
    int Memoization(vector<vector < int>> &dp, int ind, int amount, vector< int > &coins)
        {
            if (amount == 0)
               	//Koi amount hi nahin to 1 hi tarika hain ki kuch mat karo
               	//Yeh bhi apne aap mein tarika hain
                return 1;
            if (ind == coins.size())
               	//Amount 0 nahin hua lekin coins khatam to koi tarika nahin
                return 0;
            if (dp[ind][amount] != -1)
               	//Pehle se problem solved hain
                return dp[ind][amount];
            if (coins[ind] > amount)
               	//Coin amt greater than amount to skip karo is coin ko
                return dp[ind][amount] = Memoization(dp, ind + 1, amount, coins);
            int pick = Memoization(dp, ind, amount - coins[ind], coins);
            int notPick = Memoization(dp, ind + 1, amount, coins);
            return dp[ind][amount] = pick + notPick;
        }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
        return Memoization(dp, 0, amount, coins);
    }
};