class Solution {
public:
    int hasCycle(int sv,vector<vector<int>> &edges, vector<bool> &vis, set<int> &S)
    {
        vis[sv] = true;
        S.insert(sv);
        for(int i=0;i<edges[sv].size();i++)
        {
            if(S.find(edges[sv][i]) != S.end()) return sv;
            if(!vis[edges[sv][i]]){
                int x = hasCycle(edges[sv][i],edges,vis,S);
                if(x != -1) return x;
            }
        }
        S.erase(sv);
        return -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            if(edges[i] != -1) v[edges[i]].push_back(i);
        }
        vector<bool> vis(edges.size(),false);
        int ans = -1;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            set<int> S;
            int getAns = hasCycle(i,v,vis,S);
            if(getAns > -1)
            {
                int c = 1;
                int sv = i;
                while(edges[sv] != i){
                    sv = edges[sv];
                    c++;
                }
                ans = max(ans,c);
            }
        }
        return ans;
    }
};