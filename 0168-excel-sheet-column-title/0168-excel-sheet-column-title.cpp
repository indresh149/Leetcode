class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber>0)
        {
            int r=columnNumber%26;
            if(r==0)
            {
                res+='Z';
                columnNumber=columnNumber/26;
                columnNumber--;
            }
            else{
                res+=char(r+64);
                columnNumber=columnNumber/26;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};