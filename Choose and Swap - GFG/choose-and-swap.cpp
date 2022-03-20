// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        map<char,bool> hit;
        for(char c:a)
        {
            hit[c] = true;
        }
        for(char c: a)
        {
            for(char d = 'a';d < c; ++d)
            {
                if(hit[d])
                {
                    for(char &cc : a)
                    {
                        if(cc == d)
                         cc = c;
                         
                         else if(cc == c)
                         {
                             cc = d;
                         }
                    }
                    return a;
                }
            }
            hit[c] = false;
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends