class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
	   int longest = 0;
	   for(int num : s) {
        if(s.count(num - 1)) continue;
		int j = 1;
		while(s.count(num + j)) j++; 
		longest = max(longest, j);
	}
	return longest;
        }
};