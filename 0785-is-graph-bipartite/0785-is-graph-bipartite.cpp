class Solution {
public:
    bool dfs(vector<vector<int>> graph, int curr, vector<int> &colors, int color){
        colors[curr] = color;
        for(auto vertex : graph[curr])
            if(!colors[vertex] && !dfs(graph, vertex, colors, -color)) return false;
            else if(colors[vertex] == color) return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++)
            if(!colors[i] && !dfs(graph, i, colors, 1)) return false;
        return true;
    }
};