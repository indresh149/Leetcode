class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n= nums.size();
        vector<int> a(2*n + 1,INT_MIN);
        a[n]=-1;
        int maxLen =0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+(nums[i] == 0 ? -1 :1);
            if(a[sum + n] >= -1) maxLen = max(maxLen,i - a[sum + n]);
            else a[sum + n]=i;
        }
        return maxLen;
        
    }
};