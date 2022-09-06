class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //to store answer
        vector<vector<int>> ans(maze.size(),vector<int>(maze[0].size(),0));
        //to store coordinate
        queue<pair<int,int>> q;
        //start bfs fron entrance
        q.push({entrance[0],entrance[1]});
        //mark entrance different from others (like '0')
        maze[entrance[0]][entrance[1]]='0';
        //distance
        ans[entrance[0]][entrance[1]]=0;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            //if this coordinate is not entrance and also at border then this is the answer
            if((maze[x][y]!='0') &&(x==0 || x==maze.size()-1 ||y==0 ||y==maze[0].size()-1)){
                return ans[x][y];
            }
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                //store valid '.' coordinates & to mark them visited store '1' in maze[x1][y1]
				//also increase distance by 1 in ans array 
                if(x1>=0 && y1>=0 && x1<maze.size() && y1<maze[0].size()&& maze[x1][y1]=='.'){
                    maze[x1][y1]='1';
                    ans[x1][y1]=ans[x][y]+1;
                    q.push({x1,y1});
                }
            }
        }
        return -1;
    }
};