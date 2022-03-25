class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> ref;
        int n = costs.size()/2;
        int mincost =0;
        for(auto cost: costs)
        {
            mincost += cost[0];
            ref.push_back(cost[1] - cost[0]);
        }
        sort(ref.begin(),ref.end());
        for(int i=0;i<n;i++)
        {
            mincost += ref[i];
        }
        return mincost;
    }
};