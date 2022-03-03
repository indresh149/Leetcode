// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    unordered_map<char,pair<int,int>> mp;
    unordered_map<char,char> change;
    
    pair<int,int> func(vector<vector<int>> &grid, int i, int j, pair<int,int> last, char dir){
        if(i < 0 || i >= grid.size() || j<0 || j>= grid[0].size()){
            return last;
        }
        last = {i,j};
        if(grid[i][j] == 0){
            auto p = mp[dir];
            return func(grid , i+ p.first, j+p.second, last, dir);
        }
        grid[i][j] = 0;
        char ndir = change[dir];
        auto p = mp[ndir];
        func(grid, i+ p.first, j+ p.second, last, ndir);
    }
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        mp['u'] = {-1,0};
        mp['d'] = {1,0};
        mp['l'] = {0,-1};
        mp['r'] = {0,1};
        
        change['u'] = 'r';
        change['r'] = 'd';
        change['d'] = 'l';
        change['l'] = 'u';
        
        return func(matrix,0,0,{0,0},'r');
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends