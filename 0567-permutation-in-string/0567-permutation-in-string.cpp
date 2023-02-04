class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        for(auto p:s1) map[p-'a']++;
        int i=0,j=0,counts1 = s1.size();
        while(j<s2.size())
        {
            if(map[s2.at(j++) - 'a']--> 0)
            {
                counts1--;
            }
            if(counts1 == 0) return true;
            if(j - i == s1.size() && map[s2.at(i++)-'a']++ >=0)
            {
                counts1++;
            }
        }
        return false;
    }
};