class Solution {
public:
    string largestGoodInteger(string num) {
         int mx = -1;
         int flag = 0;
    if (num.size() == 3){
        if (num[0] == num[1] && num[1] == num[2]){
            if (num[0] == '0')
                return "000";
            else
                return to_string((num[0]-'0') * 100 + (num[0]-'0') * 10 + (num[0]-'0'));
        }
    }
    for (int i = 0; i < num.size() - 2; i++)
    {
        if (num[i] == num[i + 1] && num[i] == num[i + 2])
        {
            if (num[i] - '0' > mx)
            {
                flag = 1;
                mx = num[i] - '0';
            }
        }
    }
    if (mx == 0)
        return "000";
    if (mx != -1)
        return to_string(mx * 100 + mx * 10 + mx);
    return "";
        }
    
};