class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int net_profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prices[i-1]) net_profit+=prices[i]-prices[i-1];
        }
        return net_profit;
    }
};