class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        multiset<int, greater<int>> s;
        
        for(auto n:m){
            s.insert(n.second);
        }
        int siz = arr.size();
        int cnt = 0;
        int ans = 0;
        
        for(auto it = s.begin();cnt*2<siz;it++)
        {
            ans++;
            cnt += *it;
        }
        return ans;
    }
};