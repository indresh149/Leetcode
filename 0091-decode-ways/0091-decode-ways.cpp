class Solution {
public:
    int numDecodings(string s) {
       int size = s.size();
        vector<int> M; 
        M.push_back(0); 
        M.push_back(1); 
        M.push_back(s[0]!='0'); 
        
        int res = 0;
        for(int i = 2; i<=size; i++){
            res = 0;
            
            if(s[i-1]!='0')
                res += M[i];

           
            if(s[i-2] == '1' ||  s[i-2] == '2' && s[i-1] < '7' )
                res += M[i-1];
            
            M.push_back(res);
        }
        
        return M[size+1];
    }
};