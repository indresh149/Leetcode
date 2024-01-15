class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        vector<vector<int>>ans;
        vector<int>v1;
        vector<int>v2;

        set<int> w , l;
        unordered_map<int , int>tot;
        for(auto it: matches)
        {
            w.insert(it[0]);
            l.insert(it[1]);
            tot[it[1]]++;
        }

        for(auto it:w)
        {
            if(tot.find(it)==tot.end())
               v1.push_back(it);
        }
         for(auto it :l)
         {
             if(tot[it]==1)
              v2.push_back(it);
         }

         ans.push_back(v1);
         ans.push_back(v2);

         return ans;
        
    }
};