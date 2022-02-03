class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int l=1;
        int h=n;
        int mid;
       while(l<h){
        mid=(l+h)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) h=mid;
        else l=mid+1; 
    }
    return l;
    }
};