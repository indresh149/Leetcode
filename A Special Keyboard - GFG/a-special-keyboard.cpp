// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        int alpha[26];
        
        for(int i = 0; i < S1.length(); i++) {
            alpha[S1[i] - 'a'] = i;    
        }
        
        int ans = 0;
        int prev = -1;
        
        for(int i = 0; i < S2.length(); i++) {
            int j = alpha[S2[i]-'a'];
            if(prev == -1) {
                ans += j;
                prev = j;
            }
            else {
                ans += abs(prev - j);
                prev = j;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends