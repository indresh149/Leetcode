class Solution {
    public int reductionOperations(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int prev = nums[0];
        int ans = 0;
        for(int i=1;i < n;i++){
            if(prev != nums[i]){
                ans += n-i;
                prev = nums[i];
            }
        }
        return ans;
    }
}