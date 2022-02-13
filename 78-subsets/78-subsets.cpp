class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v={{}};
        for(int i:nums)
        {
            int n= v.size();
            for(int j=0;j<n;j++)
            {
                v.push_back(v[j]);
                v.back().push_back(i);
            }
        }
        return v;
    }
};