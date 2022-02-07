class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        int n=cost.size();
        if(n==1)
        {
            return cost[0];
        }
        if(n==2)
        {
            return cost[0]+cost[1];
        }
        sort(cost.begin(),cost.end());
        for(int i=n-1;i>=0;i-=2)
        {
            sum=sum+cost[i];
            if(i>=1)
            {
                sum+=cost[i-1];
            }
            i--;
        }
        return sum;
    }
};