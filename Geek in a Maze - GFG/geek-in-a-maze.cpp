// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		if (mat[r][c] == '#')
	return 0;
	
queue<vector<int>> que;
int cnt = 0;
int i = 0;
int j = 0;

mat[r][c] = '#';
que.push({r, c, u, d});

while (que.size())
{
	auto &f = que.front();
	int rr = f[0];
	int cc = f[1];
	int uu = f[2];
	int dd = f[3];
	que.pop();
	
	++ cnt;
	
	// left
	i = rr;
	j = cc - 1;
	
	if (0 <= j && mat[i][j] == '.')
	{
		mat[i][j] = '#';
		que.push({i, j, uu, dd});
	}
	
	// right
	i = rr;
	j = cc + 1;
	
	if (j < m && mat[i][j] == '.')
	{
		mat[i][j] = '#';
		que.push({i, j, uu, dd});
	}
	
	// up
	i = rr - 1;
	j = cc;
	
	if (0 <= i && mat[i][j] == '.' && uu)
	{
		mat[i][j] = '#';
		que.push({i, j, uu - 1, dd});
	}
	
	// down
	i = rr + 1;
	j = cc;
	
	if (i < n && mat[i][j] == '.' && dd)
	{
		mat[i][j] = '#';
		que.push({i, j, uu, dd - 1});
	}
}

return cnt;
	}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends