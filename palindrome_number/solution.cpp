class Solution {
public:
    bool isPalindrome(int x) {
       long long int n=x,r,sum=0,temp;    
  
   
 temp=n;    
 while(n>0)    
{    
 r=n%10;    
 sum=(sum*10)+r;    
 n=n/10;    
}    
if(temp==sum)    
return true;    
else    
   return false;  
    }
};