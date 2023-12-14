class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> orows(n);
        vector<int> ocol(m);
        
        vector<int> zrow(n);
        vector<int> zcol(m);
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++){
                
                if(grid[i][j] == 1)
                {
                    orows[i] += 1;
                    ocol[j] += 1;
                }
                else
                {
                    zrow[i]+=1;
                    zcol[j]+=1;
                }
            }
        }
        vector<vector<int>> diff(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                diff[i][j] = orows[i] + ocol[j] - zrow[i] - zcol[j];
            }
        }
        return diff;
        
    }
};