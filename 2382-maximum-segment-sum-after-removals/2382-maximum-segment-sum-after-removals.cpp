typedef long long int ll;

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        int q = removeQueries.size();
        
        vector<ll> prefix(n+1);
        for(int j = 1;j <= n;j++)
        {
            prefix[j] = prefix[j-1]+nums[j-1];
        }
        
        multiset<ll> all;
        all.insert(prefix[n]);
        all.insert(0);
        
        set<int> removed;
        vector<ll> result;
        
        for(auto i: removeQueries){
            i++;
            
            auto nxt_itr = removed.upper_bound(i);
            int last_ind = n;
            if(nxt_itr != removed.end()) last_ind = *nxt_itr - 1;
            
            int start_ind = 1;
            if(nxt_itr != removed.begin()){
                --nxt_itr;
                start_ind = *nxt_itr + 1;
            }
            
            ll range_sum = prefix[last_ind] - prefix[start_ind-1];
            all.erase(all.find(range_sum));
            
            //[start_ind, i-1]
            if(i-1 >= start_ind)all.insert(prefix[i-1] - prefix[start_ind-1]);
            
            //[i+1,last_ind]
            if(last_ind >= i+1)all.insert(prefix[last_ind]-prefix[i]);
            
            result.push_back(*all.rbegin());
            removed.insert(i);
        }
      return result;
    }
};