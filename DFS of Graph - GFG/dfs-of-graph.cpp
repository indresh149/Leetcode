// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    void Dfsrec(vector<int> adj[],int s,vector<int>&visited){
       visited[s]=1;
       cout<<s<<" ";
       for(auto x:adj[s]){
           if(visited[x]==false){
               Dfsrec(adj,x,visited);
           }
       }
   }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
          vector<int>visited(v+1,0);
       for(int i=0;i<v;i++){
           if(visited[i]==false){
               Dfsrec(adj,i,visited);
           }
       }
       return {};
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends