// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
         int ldis=0;
       function<void(int,int,int)>dfs=[&](int node,int par,int dis){
      
         for(auto it : adj[node])  {
           
           
              
             if(it!=par){
               ldis=max(ldis,dis+1);
                 dfs(it,node,dis+1);
             }
         }
       };
       int ans = INT_MAX;

       for(int i=1; i<=N; i++){
           ldis=0;
           dfs(i,-1,0);
           
           ans=min(ans,ldis);
       }
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends