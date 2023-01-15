class Solution {
public:
    int dFind(int node,vector<int> &dsu) {
        if(node!=dsu[node])
            dsu[node] = dFind(dsu[node],dsu);
        return dsu[node];
    }
    
    void dUnion(int a,int b,vector<int> &dsu) {
        int pa = dFind(a,dsu);
        int pb = dFind(b,dsu);
        int pp = max(pa,pb);
        dsu[pa] = pp;
        dsu[pb] = pp;
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int count = 0;
        int n = vals.size();
        vector<int> dsu(n);
        iota(dsu.begin(),dsu.end(),0);
        unordered_map<int,vector<vector<int>>> newEdges;
        unordered_map<int,vector<int>> indexes;
        
        for(int i = 0;i<n;i++)
            indexes[vals[i]].push_back(i);
        
        for(vector<int> &edge : edges) {
            int highVal = max(vals[edge[0]],vals[edge[1]]);
            newEdges[highVal].push_back(edge);
        }
        
        int ans = 0;
        
        int low = *min_element(vals.begin(),vals.end());
        int high = *max_element(vals.begin(),vals.end());
        for(int nodeVal = low;nodeVal<=high;nodeVal++) {
            for(vector<int> &edge : newEdges[nodeVal])
                dUnion(edge[0],edge[1],dsu);
            
            unordered_map<int,int> freq;
            for(int &ind : indexes[nodeVal]) {
                int groupNo = dFind(ind,dsu);
                freq[dFind(ind,dsu)]++;
            }
            
            for(const pair<int,int> &group : freq) {
                int count = group.second;
                ans+= (count*count-count)/2;
            }
        }
        ans+=n;
        return ans;
    }
};