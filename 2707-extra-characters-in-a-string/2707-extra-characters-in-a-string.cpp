class Solution {
public:
   int dp[51] = {};
int minExtraChar(const string &s, vector<string>& dict, int i = 0) {
    if (i == s.size())
        return 0;
    if (dp[i] == 0) {
        dp[i] = 2 + minExtraChar(s, dict, i + 1);
        for (const auto &w: dict)
            if (i + w.size() <= s.size() && s.compare(i, w.size(), w) == 0)
                dp[i] = min(dp[i], 1 + minExtraChar(s, dict, i + w.size()));
    }
    return dp[i] - 1;
}
};