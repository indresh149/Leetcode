class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>&b)
    {
       if(a[0] != b[0]){
           return a[0] < b[0];
       }
        return a[1] < b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        int n=events.size();
        int ans = 0;
        int i=0;
        
        multiset<int> s;
        for(int j=1;j <100001; ++j){
            while(!s.empty() && *(s.begin())<j){
                s.erase(s.begin());
            }
            
            while(i<n && events[i][0] == j){
                s.insert(events[i][1]);
                i++;
            }
            if(s.size()>0){
                ans++;
                s.erase(s.begin());
            }
        }
        return ans;
        
    }
};