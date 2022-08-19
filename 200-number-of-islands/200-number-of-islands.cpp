class Solution {
public:
     void dfs(int r,int c,int n,int m,vector<int> & dr,vector<int> &dc,vector<vector<char>> &grid,vector<vector<int>> & visited)
    {
        visited[r][c]=1;
        
        for(int i=0;i<4;i++)
        {
          int nr=r+dr[i],nc=c+dc[i];
                
              if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !visited[nr][nc])  
              { dfs(nr,nc,n,m,dr,dc,grid,visited);}
            
        }
        
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
      int m=grid[0].size();  
      vector<vector<int>> visited(n,vector<int>(m,0));
      int count=0;  
      vector<int> dr,dc;
      dr={-1,1,0,0};
       dc={0,0,-1,1}; 
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]=='1' && !visited[i][j])
              {
                  count++;
                  dfs(i,j,n,m,dr,dc,grid,visited);
              }
          }
      }
    return count;    
    }
};