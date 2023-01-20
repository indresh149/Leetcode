class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int> &nums,int prev,int i,vector<int> &v){
        if(i == nums.size()){
            if(v.size() >= 2){
                ans.insert(v);
            }
            return;
        }
        if(nums[i] >= prev){
            v.push_back(nums[i]);
            solve(nums,nums[i],i+1,v);
            v.pop_back();
        }
        solve(nums,prev,i+1,v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        ans.clear();
        solve(nums,-101,0,v);
        
        vector<vector<int>> rans;
        
        for(auto x:ans){
            rans.push_back(x);
        }
        return rans;
    }
};