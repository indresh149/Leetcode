// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void dfs(vector<int> graph[],bool visited[],int &cnt,int src,int val)
    {
        visited[src] = true;
        if(val%2) cnt++;
        for(auto it:graph[src])
            if(!visited[it]) 
                dfs(graph,visited,cnt,it,val+1);
    }
    int countOfNodes(vector<int> graph[], int n)
    {
        // code here
         bool visited[n+1] = {0};
        int cnt = 0;
        dfs(graph,visited,cnt,1,0);
        return cnt*(cnt-1)/2 + (n - cnt)*(n - cnt -1)/2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends