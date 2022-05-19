// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.size()-B.size()!=0)
            return -1;
        
        int i=A.size()-1, j=B.size()-1;
        vector<int> v(256);
        
        while(i>=0 && j>=0)
        {
            if(A[i]==B[j])
            {
                i--, j--;
            }
            else
            {
                while(i>=0 && A[i]!=B[j])
                {
                    v[A[i]]++;
                    i--;
                }
                
                if(i>=0)
                    i--, j--;
            }
        }
        
        
        int ans=0;
        while(j>=0)
        {
            ans++;
            v[B[j]]--;
            
            
            if(v[B[j]]<0)
            {
                return -1;
            }
            j--;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends