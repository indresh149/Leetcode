class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
       unordered_map<int, int> f;
        int res = 0;
        for(int i:nums){
            res += f[i-k] + f[i+k];
            
            f[i]++;
        }
        return res;
    }
};