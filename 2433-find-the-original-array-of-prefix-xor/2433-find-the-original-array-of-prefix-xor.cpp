class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
          int n=pref.size();
        
          vector<int> cnt;
        
        cnt.push_back(pref[0]);
        
        for(int i=0;i<n-1;i++)
        {
            
            cnt.push_back(pref[i]^pref[i+1]);
        }
        
        return cnt;
    }
};