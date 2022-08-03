class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        
        for(string s:sentences){
            int cnt = 1;
            for(int j=0;j<s.length();j++){
                if(s[j] == ' ')
                {
                    cnt++;
                }
                
                maxi  = max(maxi,cnt);
            }
        }
        return maxi;
    }
};