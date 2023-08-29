class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> ps_Y(n,0);
        vector<int> ps_N(n,0);
        
        ps_Y[0] = customers[0] == 'Y' ? 1 : 0;
        ps_N[0] = customers[0] == 'N' ? 1: 0;
        
        for(int i=1;i<n;i++){
            ps_Y[i] += ps_Y[i-1];
            ps_N[i] += ps_N[i-1];
            
            if(customers[i] == 'Y'){
                ps_Y[i]++;
            }
            else{
                ps_N[i]++;
            }
        }
        
        int mp = INT_MAX,mp_i = 0;
        
        for(int i=0;i <= n;i++){
            int before_penalty = (i > 0) ? ps_N[i-1] : 0;
            int after_penalty = (i < n) ? (ps_Y[n-1] - ((i > 0) ? ps_Y[i-1] : 0)) : 0;
            
            int total_penalty = before_penalty + after_penalty;
            
            if(mp > total_penalty){
                mp = total_penalty;
                mp_i = i;
            }
        }
        return mp_i;
    }
};