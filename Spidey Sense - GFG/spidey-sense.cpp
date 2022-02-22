// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    bool isValid(int x,int y,int M,int N,vector<vector<bool>>&vis , vector<vector<char>> &matrix){
        if(x<0 || x>=M || y<0 || y>=N) return (false);
        if(vis[x][y]|| matrix[x][y] == 'W') return false;
        return true;
    }
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        // Your code goes here
        vector<vector<int>> dis(M,vector<int>(N,-1));
        vector<vector<bool>> vis(M,vector<bool>(N,false));
        queue<pair<int,int>> q;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j] == 'B'){
                    q.push({i,j});
                    dis[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i =0;i<4;i++){
                int nx = x+dx[i];
                int ny = y + dy[i];
                if(isValid(nx,ny,M,N,vis,matrix)){
                    dis[nx][ny] = dis[x][y] +1;
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return dis;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends