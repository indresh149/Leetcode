class Solution {
public:

    vector<int>group;
    vector<int>profit;
    int minprofit;
    int mod = 1e9 + 7;
    int dp[101][101][101];
    int find(int id,int n,int totalprofit){
        
        if(id==profit.size()) return 0;
        if(dp[id][n][totalprofit]!=-1) return dp[id][n][totalprofit];
        //if we are at current index we either choose or not choose
        //if choose
        int ans = 0;
        if(n >= group[id]){ //if we can choose
            int newprofit = max(0,totalprofit - profit[id]);
            if(newprofit <= 0) ans+= (1 + find(id + 1,n-group[id],newprofit)%mod)%mod;
            else ans+= find(id + 1,n-group[id],newprofit)%mod;
        }
        
        //if we don not choose
        ans%=mod;
        ans+=find(id+1,n,totalprofit)%mod;
        ans = ans%mod;
        return dp[id][n][totalprofit] = ans%mod;
    }
    int profitableSchemes(int n, int _minProfit, vector<int>& _group, vector<int>& _profit) {
        minprofit = _minProfit;
        group = _group;
        profit = _profit;
        for(int i = 0;i<101;i++){
            for(int j = 0;j<101;j++){
               for(int k = 0;k<101;k++){
                    dp[i][j][k]  = -1;
                }
            }
        }
        int ans = find(0,n,minprofit)%mod;
        if(minprofit==0) ans++;
        ans%=mod;
        return ans;
    }
};