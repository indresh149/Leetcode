// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int> primeRange(int M, int N) {
        // code here
        vector <int> v;
        bool prime[N+1];
        memset(prime,true,sizeof(prime));
        prime[0]=false;
        prime[1]=false;
        for(int p=2;p*p<=N;p++)
        {
            if(prime[p]==true)
            {
                for(int i=p*p;i<=N;i+=p)
                {
                    prime[i]=false;
                }
            }
        }
        for (int p = M; p <= N; p++)
        {
        if (prime[p])
        {
            v.push_back(p);
        }
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends