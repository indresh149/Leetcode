class Solution{
public:
int minScore(int n, vector<vector<int>>& redge) {

         int k=redge.size();
        vector<vector<pair<int,int>>>ds(n+1);
        for(int i=0;i<k;i++)
        {
            ds[redge[i][0]].push_back({redge[i][1],redge[i][2]});
            
            ds[redge[i][1]].push_back({redge[i][0],redge[i][2]});
        }

        vector<int>visited(n+2,0);

        queue<vector<int>>qu;
    
    
        qu.push({n,INT_MAX});
    
        int mini=INT_MAX;

        while(!qu.empty())
        {
            auto tp=qu.front();
            
            qu.pop();
            
            mini=min(mini,tp[1]);
            
            visited[tp[0]]=1; 
            
            for(auto it:ds[tp[0]])
            {
                if(!visited[it.first])
                {
                    qu.push({it.first,it.second});
                }
            }
        }
        return mini;
}
};