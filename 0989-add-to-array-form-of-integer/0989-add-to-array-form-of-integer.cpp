class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       vector<int>ans;
        int c = 0;
        for(int i=num.size()-1;i>=0;i--){
           int nm = num[i] + k%10 + c;
           ans.push_back(nm%10);
           c=nm/10;
           k/=10;
        }
        while(k || c){
            int nm = k%10 + c;
            ans.push_back(nm%10);
            c=nm/10;
            k/=10;
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};