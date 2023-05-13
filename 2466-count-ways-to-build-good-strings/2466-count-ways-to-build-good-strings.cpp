
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> res(200005);
        
        set<int> st ;
        
        for(int j =0; j< 10 ; j++)
        {
            st.insert(j);
            
        }
        long long mod  = 1e9+7;
        
        res[0] = 1;
        
        
        for(int i = 0; i < 1e5; i++)
        {
            res[i + zero] %= mod;
            
            res[i + zero] += res[i];
            
             res[i + one] %= mod;
            
           res[i + one] += res[i];
            
        }
        long long s = 0;
        
        for(int i = low; i <= high; i++)
        {
            //cout<<s
            s = (s + res[i])%mod;
        }
        return s;
    }
};