// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long isPrime(long long n)
{
if(n<=1)
{
 return 0;
}
for(long long i = 2;i*i<=n;i++)
{
 if(n%i==0)
 {
  return 0;
 }
}
return 1;
}
public:
   long long primeProduct(long long L, long long R){
       // code 
       long long product = 1;
       long long m = 1e9+7;
       for(long long i = L;i<=R;i++)
       {
           if(isPrime(i))
           {
               product = (product * (i)%m)%m;
           }
       }
       return product;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends