class Solution {
public:
    bool isPossible(vector<int>& nums) {
         unordered_map<int, int> freq, appendfreq;
        for (int i: nums) {
            freq[i]++;
        }
        
        for(int i : nums){
            if(freq[i] == 0) continue;
            else if(appendfreq[i] > 0)
            {
                appendfreq[i]--;
                appendfreq[i+1]++;
            }
            else if(freq[i+1] > 0 && freq[i+2] >0){
                freq[i+1]--;
                freq[i+2]--;
                appendfreq[i+3]++;
            }
            else return false;
            freq[i]--;
        }
        return true;
    }
};