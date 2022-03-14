// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int mask = 0;
        int ans;
        ans = N;
        for(int i=30;i>=0;i--)
        {
             if((X>>i)&1)
           {
               mask^=(1ll<<i);
               continue;
           }
           
           int ct=0;
           int alt_mask=mask^(1ll<<i);
           for(auto &j:A)
           {
               if((j&alt_mask)==alt_mask)
               {
                   ct++;
               }
           }
           ans = min(ans,N-ct);
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends