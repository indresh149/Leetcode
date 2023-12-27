class Solution {
public:
    int minCost(string colors, vector<int>& cost) {
        char c = '*';
        int costp = 0;
        int ans  = 0;
        for(int i=0;i<colors.size();i++){
            if(colors[i] == c){
                if(costp < cost[i]){
                    ans += costp;
                    costp = cost[i];
                }
                else{
                    ans += cost[i];
                }
            }
            else
            {
                c = colors[i];
                costp = cost[i];
            }
        }
        return ans;
    }
};