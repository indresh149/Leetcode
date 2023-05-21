class Solution {
    vector<pair<int,int>> mov{
        {1,0},{0,1},{-1,0},{0,-1}
    };
    void fill(queue<pair<int,int>> &q,int i,int j,int &n,vector<vector<int>>& grid,vector<vector<int>> &vis)
    {
        vis[i][j]=1;
        q.push({i,j});
        for(auto x:mov)
        {
            int ni=i+x.first,nj=j+x.second;
            if(ni>=0&&nj>=0&&ni<n&&nj<n&&grid[ni][nj]==1&&vis[ni][nj]==0)
            {
                fill(q,ni,nj,n,grid,vis);
            }
        }
    }

    int bfs(queue<pair<int,int>> &q,vector<vector<int>>& grid,vector<vector<int>> &vis,int &n)
    {
        int ans=0;
        while(q.size()!=0)
        {
            int len=q.size();
            while(len--)
            {
                auto e=q.front();
                q.pop();
                int i=e.first,j=e.second;
                for(auto x:mov)
                    {
            int ni=i+x.first,nj=j+x.second;
            if(ni>=0&&nj>=0&&ni<n&&nj<n&&vis[ni][nj]==0)
                {
                vis[ni][nj]=1;
                q.push({ni,nj});
                if(grid[ni][nj]==1)
                    return ans;
                }
                     }
            }
            ans++;
        }
        return -1;
        
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int flag=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                { fill(q,i,j,n,grid,vis);
                    flag=1;
                 break;
                 }
            }
            if(flag)
                break;
        }
        return bfs(q,grid,vis,n);
        
    }
};