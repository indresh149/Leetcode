class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPathAllKeys(vector<string>& grid) {
      int n=grid.size(),m=grid[0].length();
      int x=0,y=0;
      int nkey=0;
        for (int i = 0; i < grid.size(); i++) {
          
          for (int j = 0; j < grid[i].length(); j++) {
            
            if(grid[i][j]=='@'){
              x=i;
              y=j;
            }
            else if(grid[i][j]!='.'&&grid[i][j]!='#'&&islower(grid[i][j])){
              int p=grid[i][j]-'a';
              nkey=nkey|(1<<p);
            }
          }
        }
        cout<<nkey<<endl;
      // nkey=nkey>>1;
      map<pair<pair<int,int>,int>,bool>vis;
      queue<pair<pair<int,int>,int>>q;
      q.push({{x,y},0});
      vis[{{x,y},0}]=true;
      int l=1;
      
      while(!q.empty()){
        int s=q.size();
        for (int i = 0; i < s; i++) {
          auto [a,b]=q.front().first;
          int keys=q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int x1=a+dir[k][0],y1=b+dir[k][1];
            if(x1>n-1||y1>m-1||x1<0||y1<0||grid[x1][y1]=='#')continue;
            int bit=0;
            if(grid[x1][y1]=='.'||grid[x1][y1]=='@'){
              if(vis[{{x1,y1},keys}])continue;
              q.push({{x1,y1},keys});
              vis[{{x1,y1},keys}]=true;
              bit=keys;
            }
            else if(islower(grid[x1][y1])){
              int p=grid[x1][y1]-'a';
              int l=(1<<p);
              int mask=(l|keys);
              if(vis[{{x1,y1},mask}])continue;
              q.push({{x1,y1},mask});
              vis[{{x1,y1},mask}]=true;
              bit=mask;
            }
            else {
              int p=grid[x1][y1]-'A';
              int l=keys & (1<<p);
              if(l!=0){
                if(vis[{{x1,y1},keys}])continue;
                q.push({{x1,y1},keys});
                vis[{{x1,y1},keys}]=true;
                bit=keys;
              }
            }
            if(bit==nkey){
              return l;}
            
          }
          
        }
        l++;
        
      }return -1;
    }
};