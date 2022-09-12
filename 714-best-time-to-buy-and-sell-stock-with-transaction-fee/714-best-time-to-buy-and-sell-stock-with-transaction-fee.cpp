class Solution {
public:
    int maxProfit(vector<int>& values, int fee) {
        int n = values.size();
        int aheadNotBuy,aheadBuy,curBuy,curNotBuy;
    aheadNotBuy = aheadBuy = 0;
    
    for(int ind = n-1;ind>=0;ind--){
         //sell
        curNotBuy = max(values[ind]  + aheadBuy,0 + aheadNotBuy);
        
        //buy
        curBuy = max(-values[ind] - fee + aheadNotBuy,0 + aheadBuy);                       
          
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
      }
    return aheadBuy;
    }
};