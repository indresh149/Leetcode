class Solution {
public:
    void compsort(vector<vector<int>>& mat,int row,int col,int m,int n){
        int count[101] = {0};
        int r = row;
        int c = col;
        while(r < m && c < n){
            count[mat[r][c]]++;
            r++;
            c++;
        }
      
        r  =  row;
        c  = col;
        for(int i=1;i<101;i++){
            if(count[i] > 0){
                int cnt = count[i];
                while(cnt --> 0){
                    mat[r][c] = i;
                    r++;
                    c++;
                }
            }
        }
       
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        //row  = 0
        for(int col = 0;col < n;col++){
            compsort(mat,0,col,m,n);
        }
        
        //col = 0
        for(int row  = 1;row <m;row++){
            compsort(mat,row,0,m,n);
            
        }
        return mat;
    }
};