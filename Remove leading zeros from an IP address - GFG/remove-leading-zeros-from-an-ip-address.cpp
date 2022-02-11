// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string removeLeadingZero(string s)
    {
        int i=0;
        while(i<s.length() && s[i]=='0')
        {
            i++;
        }
        if(i == s.length())
        {
            return "0";
        }
        else
        {
            return s.substr(i);
        }
    }
    string newIPAdd (string s)
    {
        //code here.
        string ans = "";
        int i=0,n=s.length();
        
        while(i<n){
            string temp="";
            while(i<n && s[i]!='.')
            {
                temp += s[i++];
            }
            if(temp.size()==0)
            {
                ans+='0';
            }
            else
            {
                ans += removeLeadingZero(temp);
            }
            if(i<n)
            {
                ans+='.';
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends