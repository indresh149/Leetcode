class Solution {
public:
    int climbStairs(int n ) {
    
    int i0=1;
int i1=1;
int ans=1;
for (int i=1; i<n; i++) {
ans=i0+i1;
i0=i1;
i1=ans;
}
return ans;
}
};