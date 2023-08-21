class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = s.length()/2;i >= 1;i--){
            if(s.length()%i == 0){
                string sub = s.substr(0,i);
                string constructedString = "";
                int n = s.length()/i;
                
                for(int j = 1;j <= n;j++){
                    constructedString += sub;
                }
                
                if(constructedString == s) return true;
            }
        }
        return false;
    }
};