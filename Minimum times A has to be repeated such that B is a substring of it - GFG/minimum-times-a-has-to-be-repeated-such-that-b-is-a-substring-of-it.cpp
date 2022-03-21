// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isSubstring(string str2, string rep1)
  {
      int N = rep1.length();
      int M = str2.length();
      
      for(int i=0;i<=N-M;i++)
      {
          int j;
          for(j=0;j<M;j++)
          {
              if(rep1[i+j] != str2[j])
              {
                  break;
              }
          }
          if(j == M)
          {
              return true;
          }
      }
      return false;
  }
    int minRepeats(string A, string B) {
        // code here
        int ans = 1;
        string s = A;  
        while(s.size() < B.size())
        {
            s+= A;
            ans++;
        }
        if(isSubstring(B,s)) return ans;
        if(isSubstring(B,s+A))return ans+1;
        
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends