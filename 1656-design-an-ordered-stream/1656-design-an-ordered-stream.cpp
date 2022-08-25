class OrderedStream {
public:
    string dp[1005];
    int ptr;
    OrderedStream(int n){
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
     dp[idKey] = value;
        if(dp[ptr] != ""){
            vector<string> ans;
            for(int i=ptr;i<=1005;i++){
                if(dp[i] != ""){
                    ans.push_back(dp[i]);
                    ptr = i+1;
                }
                else
                {
                    break;
                }
            }
            return ans;
        }
        return {};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */