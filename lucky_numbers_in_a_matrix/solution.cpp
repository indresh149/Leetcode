class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int min = 1000000;
                for(int k=0;k<m;k++)
                {
                    if(matrix[i][k]<min)
                        min = matrix[i][k];
                }
                int max = 0;
                for(int l=0;l<n;l++)
                {
                    if(matrix[l][j]>max)
                        max = matrix[l][j];
                }
                if ((max==min) && (max == matrix[i][j]))
                {
                    res.push_back(matrix[i][j]);
                }
            //cout<<min <<"A"<< max<<endl;
        }
        }
        return res;
    }
};