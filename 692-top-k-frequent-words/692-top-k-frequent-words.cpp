class Solution {
public:
    #define psi pair<int, string>
    class myComparator {
  public:
    bool operator() (const psi &p1, const psi &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
    };
        
    vector<string> topKFrequent(vector<string>& words, int k) {
          int n = words.size();
        unordered_map<string, int> freq;

      for(string word : words) {
        freq[word]++;
       }
        
        priority_queue<psi, vector<psi>, myComparator> pq;
        
        for(auto it : freq) {
         pq.push({it.second, it.first});

         if(pq.size() > k) {
         pq.pop();
          }
          }
        
        vector<string> ans(k);
        int m = k-1;

          while(pq.size() > 0) {
            ans[m--] = pq.top().second;
            pq.pop();
          }

          return ans;
          
    }
};