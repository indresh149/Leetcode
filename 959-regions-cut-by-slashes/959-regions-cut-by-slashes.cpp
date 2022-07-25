class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int cnt;
    int findparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }
    
    void unionn(int u,int v){
        u = findparent(u);
        v = findparent(v);
        if(u != v)
        {
            if(rank[u] < rank[v]) parent[u] = v;
            else if(rank[u] > rank[v]) parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }   
        }
        else cnt++;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n+1;
        
        parent = vector<int>(dots*dots+1);//resize the parent vector
        rank = vector<int>(dots*dots+1);
        cnt = 1;
        
        //Initialize parent and Rank vector
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        //For all boundary elemnts having parent zero
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i == 0 || j == 0 || i == dots-1 || j == dots-1){
                    int CellNo = i*dots+j;
                    if(CellNo != 0) unionn(0,CellNo);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '/'){
                    int CellNo1 = i*dots + (j+1);
                    int CellNo2 = (i+1) * dots+j;
                    unionn(CellNo1,CellNo2);
                }
                else if(grid[i][j] == '\\'){
                    int CellNo1 = i*dots+j;
                    int CellNo2 = (i+1)*dots + (j+1);
                    unionn(CellNo1,CellNo2);
                }
            }
        }
        return cnt;
    }
};