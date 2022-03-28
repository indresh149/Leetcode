// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        for(int i=0;i<n;i++){
           if(!((1<<(p1+i)&x)>0 && (1<<(p2+i)&x)>0) && !((1<<(p1+i)&x)==0 && (1<<(p2+i)&x)==0)){
               x^=1<<(p1+i);
               x^=1<<(p2+i);
           }
       }
       return x;
    }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends