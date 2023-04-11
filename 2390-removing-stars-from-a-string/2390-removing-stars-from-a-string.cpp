class Solution {
public:
    string removeStars(string s) {
    string ans;
        
     int j=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                if(!ans.empty())
                {
                    ans.pop_back();
                }
            }
            else {
                ans +=s[i];
            }
        }
        return ans;
    }
};