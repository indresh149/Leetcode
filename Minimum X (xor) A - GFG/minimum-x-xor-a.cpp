// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int countbits(int n)
  {
      int cnt = 0;
      while(n > 0)
      {
          cnt = cnt + (n&1);
          
          n = n >> 1;
      }
      return cnt;
  }
    int minVal(int a, int b) {
        // code here
        int bitsa = countbits(a);
        int bitsb = countbits(b);
        
        int diff = abs(bitsa - bitsb);
        
        if(bitsa == bitsb) return a;
        
        else if(bitsa > bitsb)
        {
            while(diff > 0)
            {
                a = a&(a-1);
                
                diff--;
            }
        }
        else
        {
            while(diff > 0)
            {
                a = a|(a+1);
                diff--;
            }
        }
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends