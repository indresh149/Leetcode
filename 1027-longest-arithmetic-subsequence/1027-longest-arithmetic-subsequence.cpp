class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        int result = 1;
        for (int delta = 0; delta <= (maxNum - minNum) / result; delta++) {
            unordered_map<int, int> sequenceLength;
            for (int num: nums) {
                sequenceLength[num] = max(sequenceLength[num], sequenceLength[num - delta] + 1);
                result = max(result, sequenceLength[num]);
            }
        }

        for (int delta = -1; delta >= (minNum - maxNum) / result; delta--) {
            unordered_map<int, int> sequenceLength;
            for (int num: nums) {
                sequenceLength[num] = max(sequenceLength[num], sequenceLength[num - delta] + 1);
                result = max(result, sequenceLength[num]);
            }
        }
        
        return result;
    }
};