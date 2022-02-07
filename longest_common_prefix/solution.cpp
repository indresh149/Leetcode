class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<2) return strs[0];
        sort(strs.begin(),strs.end());
        string ans ="";
        int size = strs[0].size(),i=0;
        while(i<size)
        {
            if(strs[0][i]==strs[strs.size()-1][i])
            {
               ans+=strs[0][i];
                i++;
            }
            else{
                 break;
            }
        }
        return ans;
    }
};