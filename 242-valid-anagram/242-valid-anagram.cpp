class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++)
        {
            if(mp[t[i]]>0){
                mp[t[i]]--;
                continue;
            }
            if(mp[t[i]]==0){
                return false;
            }
        }
        
        return true;
    }
};