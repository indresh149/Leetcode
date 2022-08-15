class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;  // vector to store final answer
        int count[101] = {0};    // Array to store count
		int len = nums.size();
        
        //Store count of each number
        for(int i = 0; i < len; i++) {
            count[nums[i]]++;
        }
        
        //Assigning count of smaller number to that number
        for(int i = 1; i < 101; i++) {
            count[i] += count[i - 1];
        }
        
        
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0)
                ans.push_back(0);
            else
                ans.push_back(count[nums[i] - 1]);
                
        }
        return ans;
    }
};