class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();
       vector<int> pref(n);
       vector<int> suffix(n);
        
        int suma=0;
        for(int i=0;i<n;i++){
            pref[i]=suma;
            suma=suma+nums[i];
        }
       
        int sumb=0;
        for(int i=n-1;i>=0;i--)
        {
            suffix[i]=sumb;
            sumb=sumb+nums[i];
        }
      
        
        int pos=-1;
        
        for(int i=0;i<n;i++){
            if(pref[i]==suffix[i])
            {
                pos=i;
                break;
            }
        }
        return pos;
    }
    int pivotInteger(int n) {
        vector<int> ans(n+1);
        
        for(int i=1;i<=n;i++)
        {
            ans[i] = i;
        }
        
        int res  = pivotIndex(ans);
        return res;
    }
};