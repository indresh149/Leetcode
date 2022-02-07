class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=0;
        int n=digits.size()-1;
        for(int i=n;i>=0;i--)
        {
            int d=i==n ? digits[i]+1 : digits[i]+c;
            if(d==10)
            {
              digits[i]=d%10;
                c=1;
            }
            else{
                digits[i]=d;
                return digits;
            }
        }
         if(c==1)
         {
             digits.insert(digits.begin(),1);
         }
        return digits;
    }
};