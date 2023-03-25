class Solution {
public:
    int ans = 0;
   void dfs(vector<vector<int>>& adj , int u , int par  , vector<bool>& vis){
        if(!vis[u]){
            vis[u] = true;
            ans++;
            for(int i = 0 ; i<adj[u].size() ; i++){
                if(adj[u][i] == par)
                    continue;
                    dfs(adj , adj[u][i] , u , vis);
            }
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        ans = 0;
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
                 adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n , false);
        vector<int> values;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                ans = 0;
                dfs(adj , i , -1 , vis);
                values.push_back(ans);
            }
        }
        long long ans1 = 0;
        long long sum = 0;
        for(int i = 0 ; i<values.size() ; i++){
            sum += values[i];
        }
        for(int i = 0 ; i<values.size() ; i++){
            sum -= values[i];
            ans1 += sum * values[i];
        }
        return ans1;
    }
};