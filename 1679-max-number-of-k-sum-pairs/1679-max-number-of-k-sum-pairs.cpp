class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int ans = 0;
        for(auto curr:nums)
        {
            int cp = k - curr;
            if(freq[cp]> 0) {
                ans++;
                freq[cp]--;
            }
            else
                freq[curr]++;
        }
        return ans;
    }
};