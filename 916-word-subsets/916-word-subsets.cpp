class Solution {
public:
    
   unordered_map<char,int>mp;
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string>res;
    for(auto &w : words2)
    {
        unordered_map<char,int>tmp; 
        for(char &ch : w)
        {
            tmp[ch]++;
            if(tmp[ch]>mp[ch]) mp[ch]++; 
        }
    }  
    for(auto & w: words1)
    {
        unordered_map<char,int>ump;
        for(char & ch : w)
        {
            ump[ch]++;
        }
        bool isUniversal = true;
        for(auto m : mp)
        {
           
            if(m.second>ump[m.first])
            {
                isUniversal = false;
                break;
            }
        }
      
        if(isUniversal) res.push_back(w);
    }
    return res;
}
};