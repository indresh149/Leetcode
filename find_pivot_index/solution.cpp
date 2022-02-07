class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int a[n];
        int b[n];
        int suma=0;
        for(int i=0;i<n;i++){
            a[i]=suma;
            suma=suma+nums[i];
        }
       
        int sumb=0;
        for(int i=n-1;i>=0;i--)
        {
            b[i]=sumb;
            sumb=sumb+nums[i];
        }
      
        
        int pos=-1;
        //int flag=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])
            {
                pos=i;
                break;
            }
        }
        return pos;
    }
};