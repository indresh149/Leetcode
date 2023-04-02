class Solution {
public:
   // long long solve(vector<int>&s)
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int> res(spells.size());
//         long long cnt = 0;
//         for(long long i=0;i < spells.size();i++)
//         {
//             for(long long j=0;j < potions.size();j++)
//             {
//                 long long int a = long long(spells[i])*long long(potions[j]);
                
                
                
//                 if(a >= success)
//                 {
//                     cnt++;
                    
//                 }
                
//             }
//             res[i] = cnt;
            
//             cnt = 0;
//         }
//         return res;
        
        int size = spells.size(); 
        vector<int> ans(size); 
     int len = potions.size(); 
        sort(potions.begin() , potions.end()); 
        vector<int>::iterator l1; 
        for(int i = 0 ; i<spells.size() ; i++){ 
            long long  val = success/spells[i]; 
          if(success%spells[i]){ 
              val += 1; 
          } 
            l1 = lower_bound(potions.begin() , potions.end() , val); 
            int dis =  l1 - potions.begin(); 
            if(dis == len){ 
                ans[i] = 0; 
                continue; 
            } 
            else{ 
                ans[i] = len - dis; 
            } 
        } 
        return ans;
    }
};