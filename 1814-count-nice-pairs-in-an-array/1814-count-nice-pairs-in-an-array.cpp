class Solution {
public:
    int rev(int n){
        int r= 0;
        
        while(n > 0){
            r = r*10 + n%10;
            n /= 10;
        }
        
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt = 0;
        
        for(int n:nums){
            int rr = rev(n);
            int diff = n - rr;
            
            if(mp.find(diff) != mp.end()){
                cnt = (cnt + mp[diff])%1000000007;
            }
            mp[diff]++;
        }
        
        return cnt;
    }
};