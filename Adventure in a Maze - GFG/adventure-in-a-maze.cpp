// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
    // Code here
    
      int n = matrix.size(), mod = 1000000007;
   
   pair<int, int> dp[n][n];
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++)
           dp[i][j] = {0, matrix[i][j]};
   }
   
   dp[0][0].first = 1;
   
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           
           int upPath = 0, upSum = 0, leftPath = 0, leftSum = 0;
           if(i > 0 && dp[i - 1][j].first != 0 && (matrix[i - 1][j] == 2 || matrix[i - 1][j] == 3)) {
               upPath = dp[i - 1][j].first;
               upSum = dp[i - 1][j].second;
           }
           
           if(j > 0 && dp[i][j - 1].first != 0 && (matrix[i][j - 1] == 1 || matrix[i][j - 1] == 3)) {
               leftPath = dp[i][j - 1].first;
               leftSum = dp[i][j - 1].second;
           }
           
           int f = max(dp[i][j].first, (upPath + leftPath) % mod);
           int s = (dp[i][j].second + max(upSum, leftSum)) % mod;
           
           dp[i][j] = {f, s};
       }
   }
   
   int totalPath = dp[n - 1][n - 1].first;
   int maxSum = (totalPath == 0 ? 0 : dp[n - 1][n - 1].second);
   
   return {totalPath, maxSum};
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends