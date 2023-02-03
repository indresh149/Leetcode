class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
       vector<string> rows(numRows);
        bool down = true;
        
        for(int i = 0, j=0;i < s.size();i++)
        {
            rows[j].push_back(s[i]);
            if(down){
                if(j == numRows - 1){
                    j--;
                    down = false;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if(j == 0){
                    j++;
                    down = true;
                }
                else
                {
                    j--;
                }
            }
        }
        string ans;
        for(int i=0;i<rows.size();i++){
            ans += rows[i];
        }
        return ans;
    }
};