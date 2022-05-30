// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool isValid(int i, int j, int n, int m){
         if(i<0 || j<0 || i>=n || j>=m)
            return false;
         return true;
    }
    int dfs(int i, int j, int n,int m, vector<vector<int>> &dp , vector<vector<int>> &matrix){
        
        if(isValid(i,j,n,m)==false)
         return 0;
         
        if(dp[i][j] != -1)
         return dp[i][j];
        
        int down = 0, up = 0, right = 0, left =0;
        
        // down
        if( isValid(i+1, j, n, m) && matrix[i+1][j]>matrix[i][j]){
            down = dfs(i+1, j, n, m , dp , matrix);
        }
        
        // up
        if(isValid(i-1, j, n, m) and matrix[i-1][j]>matrix[i][j]){
            up = dfs(i-1, j , n, m , dp , matrix);
        }
        
        //right
        if(isValid(i, j+1, n, m) and matrix[i][j+1]>matrix[i][j]){
            right = dfs(i, j+1 , n, m , dp , matrix);
        }
        
        // left
        if(isValid(i, j-1, n, m) and matrix[i][j-1]>matrix[i][j]){
            left = dfs(i, j-1 , n, m , dp , matrix);
        }
        
        dp[i][j]= 1 + max( max(down,up) , max(right,left) );
        return dp[i][j];
    }
  
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]==-1){
                    ans = max(ans , dfs(i,j,n,m,dp,matrix));
                }
            }
        }
        return ans;;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends