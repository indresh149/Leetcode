class Solution {
public:
    int lengthOfLastWord(string s) {
          int n=s.length();
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                count=0;
            }
            else{
            count++;
                if(i>0 && s[i]!=' ' &&s[i-1]==' ')
                {
                    return count;
                }
                else if(i==0)
                {
                    return count;
                }
            }
        }
        return 1;
    }
};