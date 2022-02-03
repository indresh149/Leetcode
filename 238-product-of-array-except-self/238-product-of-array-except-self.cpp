class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> begin(n);
        begin[0]=1;
        vector<int> last(n);
        last[0]=1;
        for(int i=1;i<n;i++)
        {
            begin[i] =begin[i-1]*nums[i-1];
            last[i] = last[i-1]*nums[n-i];                        
        }
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            res[i]=begin[i]*last[n-1-i];
        }
        return res;    
    }
};