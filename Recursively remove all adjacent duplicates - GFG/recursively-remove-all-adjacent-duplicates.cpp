// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string S){
        // code here
        if(S=="")
      return S;
      lable:
      int n=S.length();
      S+="  ";
      int i=0,c=0;
      string b="";
      while(i<n)
      {
          if(S[i]==S[i+1])
          {c++;
              for(int k=i;k<n;k++)
              {
                  if(S[k]!=S[k+1])
                  {i=k+1;
                  break;}
              }
          }
          else
          {
              b+=S[i];
              i++;
              
          }
          
      }
      if(c==0)
      return b;
      else
      {
          S=b;
          goto lable;
      }
      
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends