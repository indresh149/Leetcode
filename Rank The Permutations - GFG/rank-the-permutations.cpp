// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
const int MAX = 20;
class Solution{
  public:
    long long findRank(string str) {
        //code here
        long long dp[MAX];
        dp[0] = 1;
        for(int i=1;i<MAX;i++)
        {
            dp[i] = dp[i-1]*i;
        }
        int n= str.length(),f[26] = {0};
        for(int i=0;i<n;i++)
        {
            f[str[i] - 'a']++;
            
        }
        long long rank =1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(f[j])
                {
                    if('a'+j == str[i]){
                        f[j]--;
                        break;
                    }
                    else
                    rank += dp[n-1-i];
                }
            }
        }
        return rank;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends