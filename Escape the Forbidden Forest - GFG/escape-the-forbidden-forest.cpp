// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
     vector<vector<int>> dp;
   int rec(string &str1, string &str2,int i,int j){
       if(i<0 or j<0)return 0;
       
       if((i==0 or j==0) and (str1[i]==str2[j])) return 1;
       
       if(dp[i][j]!=-1)
           return dp[i][j];
           
       int ans=0;
       if(str1[i]==str2[j])
           ans = rec(str1,str2,i-1,j-1)+1;
       else
           ans = max(rec(str1,str2,i,j-1),rec(str1,str2,i-1,j));
           
       return dp[i][j] = ans;
   }
    int build_bridges(string str1, string str2)
    {
        // code here
        int n1 = str1.size(); int n2 = str2.size();
      dp.resize(n1,vector<int>(n2,-1));
     return rec(str1,str2,n1-1,n2-1);
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends