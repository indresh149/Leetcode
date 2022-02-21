// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[101][101][101];
    int sol(int k[],int f[],int l,int r,int h){
        if(l>r) return 0;
        if(dp[l][r][h]!= -1) return dp[l][r][h];
        
        int t = INT_MAX;
        for(int i=l;i<=r;i++){
            t = min(t,h*f[i]+sol(k,f,l,i-1,h+1) + sol(k,f,i+1,r,h+1));
        }
        return dp[l][r][h] = t;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        memset(dp,-1,sizeof dp);
        return sol(keys,freq,0,n-1,1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends