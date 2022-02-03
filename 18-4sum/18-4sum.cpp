class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long sum;
        
        for(long i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(long j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int l=j+1,r=n-1;
                
                while(l<r)
                {
                    sum=(long)nums[i]+(long)nums[j]+(long)nums[l]+(long)nums[r];
                    if(sum>target)
                    {
                        r--;
                    }
                    else if(sum == target){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[l]);
                        t.push_back(nums[r]);
                        ans.insert(t);
                        l++;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto i: ans)
        {
            res.push_back(i);
        }
        return res;
    }
};