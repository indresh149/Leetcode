class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, len = mat.size();
        for(int i = 0; i < len ; i++)
            sum += mat[i][i] + mat[i][len - i - 1];
        return len % 2 ? sum - mat[len / 2][len / 2] : sum;
    }
};