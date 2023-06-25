#define mod 1000000007
class Solution { 

  int dp[101][201] ;
  
  int solve(int i,vector<int>&nums,int fuel,int last) {
   
   int n=nums.size() ; 
   
    if(dp[i][fuel] !=-1) return dp[i][fuel] ;

  int ans=0 ;
    if(i==last) {
      
         ans++; 
     
    }
 
    for(int j=0;j<n;j++){

        int d=abs(nums[i]-nums[j]) ;   
        if(d!=0 && fuel >=d) {
            ans+= solve(j,nums,fuel-d,last)  ;
             ans=ans%mod;
        }
    }
  return dp[i][fuel]= ans;
  }



public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

   memset(dp,-1,sizeof(dp)) ;

      return solve(start,locations,fuel,finish) ;  
    }
};