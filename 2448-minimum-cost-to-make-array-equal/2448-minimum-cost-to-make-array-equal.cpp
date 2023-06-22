class Solution {
public:
    // time : nlogn for sorting
    // space : n because of v vector
    long long solve(vector<int>& nums, vector<int>& cost,int median)
    {
        long long ans =0;
        for(int i=0;i<nums.size();i++)
            ans+= 1L*abs(median - nums[i]) *cost[i];
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long total = 0;
        long long sum = 0;
        long long median;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],cost[i]});
        sort(v.begin(),v.end());
        //total count or you can say total cost will help to find median
        for(auto i:v) sum+=i.second;
        int i=0;
        // while(total<(sum+1)/2 && i<nums.size())
        // {
        //     total+=v[i].second;
        //     median=v[i].first;
        //     i++;
        // }
        //below is another way to find median
        while(i<nums.size())
        {
            total+=v[i].second;
            median = v[i].first;
            if(total>=(sum+1)/2)break;
            i++;
        }
        return solve(nums,cost,median);   
    }
};
