class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int ans = 0;
        for(int i=0;i<costs.size();i++)
        {
            coins -= costs[i];
            if(coins < 0){
                break;
            }
            ans++;
        }
        return ans;
    }
};