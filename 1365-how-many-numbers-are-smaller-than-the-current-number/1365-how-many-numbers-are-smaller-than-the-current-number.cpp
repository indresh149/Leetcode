class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> mp;  // Map for storing frequencies of number less than that number
        int n = nums.size();
        
        vector<int> sortednum = nums;
        sort(sortednum.begin(),sortednum.end());
        
        //Iterating from back and assigning index of number to that number 
        for(int i = n-1;i>=0;i--)
        {
            mp[sortednum[i]] = i;
        }
        
        //Assigning frequencies to each elements
        for(int i= 0;i<n;i++){
            nums[i] = mp[nums[i]];
        }
        return nums;
    }
};