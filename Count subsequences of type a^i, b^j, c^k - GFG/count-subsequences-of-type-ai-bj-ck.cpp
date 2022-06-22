// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
       long a = 0, b = 0, c = 0, m = 1e9+7;
    for(auto &i:s){
        a = i == 'a' ? (2*a+1)%m : a;
        b = i == 'b' ? (2*b+a)%m : b;
        c = i == 'c' ? (2*c+b)%m : c;
    }
    return c;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends