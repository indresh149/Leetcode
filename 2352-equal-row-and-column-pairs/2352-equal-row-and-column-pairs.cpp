class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       int n = grid.size();
        
        int m = grid[0].size();
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j= 0;j<m;j++)
//             {
//                 for(int )
//             }
//         }
        
        vector<vector<int>> b;
        
        for(int j=0;j<m;j++)
        {
            vector<int> a;
            
            for(int i=0;i<n;i++)
            {
                a.push_back(grid[i][j]);
            }
            b.push_back(a);
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b.size();j++)
            {
                if(grid[i] == b[j]) cnt++;
            }
        }
        return cnt;
    }
};