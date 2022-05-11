// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
     string largestNumber1(int n, int sum,string &s){
       if(n==0&&sum!=0){
           s="-1";
           return s;
       }
       if(n==0&&sum==0){
           return s;
       }
       if(sum==0&&n!=0){
           s.push_back('0');
       }
       int j=9;
       while(j>0&&sum!=0){
           if(sum>=j){
             s.push_back(j+'0');
             sum=sum-j;
             break;
           }
           else
             j--;
       }
       largestNumber1(n-1,sum,s);
       return s;
   }
    string largestNumber(int n, int sum)
    {
        // Your code here
         string s="";
     return largestNumber1(n,sum,s);
     
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends