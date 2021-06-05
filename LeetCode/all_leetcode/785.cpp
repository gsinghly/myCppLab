int col[20005];
vector<vector<int>> _graph;
class Solution {
public:
    bool dfs(int s){
        for(auto i : _graph[s]){
            if(col[i] == -1){
                col[i] = 1 - col[s];
                if(!dfs(i)) return false;
            }
            else if(col[i] == col[s])       return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        _graph  = graph;
        memset(col, -1, sizeof(col));
        for(int i = 0; i < graph.size(); i++){
            if(col[i] == -1){
                col[i] = 1;
                if(!dfs(i)){
                    return false;
                }
            }
        }
        return true;
    }
};