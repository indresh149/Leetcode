class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        string ans = "";
        for(auto it:s)
        {
            if(it == ' ')
            {
                cnt++;
            }
            if(cnt == k) break;
            ans += it;
        }
        return ans;
    }
};