class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n=num1.length();
        int m=num2.length();
        int comm=0;
        int i=0;
        string s;
        while(i<n && i<m)
        {
            int res= (num1[i]+num2[i]+comm - 2*'0')%10;
            comm=(num1[i]+num2[i]+comm - 2*'0')/10;
            s.push_back(res + '0');
            i++;
        }
        while(i<n)
        {
            int res = (num1[i]+comm -'0')%10;
            comm=(num1[i]+comm -'0' )/10;
            s.push_back(res + '0');
            i++;
        }
        while(i<m)
        {
            int res = (num2[i]+ comm - '0')%10;
            comm = (num2[i] + comm - '0')/10;
            s.push_back(res + '0');
            i++;
        }
        if(comm)
        {
            s.push_back(comm + '0');
        }
        reverse(s.begin(),s.end());
        return s;
    }
};