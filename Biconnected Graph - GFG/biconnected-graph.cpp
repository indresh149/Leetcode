// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   bool articulation_point(int u, vector<int> adj[], vector<bool> &visited, int disc[], int low[] , int &time ,int parent  )
 {
     int children =0;
     visited[u]=true;
     disc[u]=low[u]= ++time ;
     
     for(auto v: adj[u])
     {
         if(visited[v]==false)
         {
             children++;
             if(articulation_point(v,adj,visited,disc, low,time , u)==true)
             {
                 return true;
             }
             
             low[u]=min(low[u],low[v]);
             
             if(parent!=-1 && low[v]>=disc[u])
             {
                 return true;
             }
             
             if(parent==-1 && children>1)
             {
                 return true;
             }
         }
         else
         {
             if(v!=parent)
             {
                 low[u]=min(low[u],disc[v]);
             }
         }
     }
     
     return false;
 }
 
    int biGraph(int arr[], int n, int e) {
        // code here
         vector<int> adj[n];
       for(int i=0;i<2*e;i=i+2)
       {
           adj[arr[i]].push_back(arr[i+1]);
           adj[arr[i+1]].push_back(arr[i]);
           
       }
       vector<bool> visited(n,false);
       int disc[n];
       int low[n];
       int parent=-1;
       int time=0;
     //  articulation
       
       if(articulation_point(0,adj,visited,disc, low, time, parent)==true)
       {
           return false;
       }
       
       for(int i=0;i<n;i++)
       {
           if(visited[i]==false)
           {
               return false;
           }
       }
       return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends