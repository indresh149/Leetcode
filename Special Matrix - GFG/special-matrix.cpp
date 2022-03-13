// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>b){
	    // Code here
	    int mod = 1e9+7;
	    vector<vector<int>> ways(n+1,vector<int>(m+1,0));
	    for(int i=0;i<b.size();i++)
	        ways[b[i][0]][b[i][1]] = -1;
	   if(ways[n][m]==-1 || ways[1][1]==-1)return 0;
	    ways[1][1] = 1;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(ways[i][j]!=-1){
	            ways[i][j]+=ways[i-1][j]+ways[i][j-1];
	            ways[i][j]%=mod;}
	            else ways[i][j]=0;
	        }
	    }
	    return ways[n][m];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends