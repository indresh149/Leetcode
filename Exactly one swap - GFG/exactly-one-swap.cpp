// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
        vector<int> f(26,0);
        int l = S.length();
        long long res =0;
        for(int i=0;i<l;i++){
            res += i- f[S[i] - 'a'];
            f[S[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(f[i] >= 2){
                res++;
                break;
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends