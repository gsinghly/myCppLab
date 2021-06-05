int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, c;
vector<vector<int>>_grid;
void dfs(int i, int j){
    _grid[i][j] = 1;  
    for(int k = 0; k < 4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !_grid[nx][ny]){
            dfs(nx, ny);
        }
    }
}
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int c = 0 ;
        _grid = grid;
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(!_grid[i][0]) dfs(i, 0);
            if(!_grid[i][m-1]) dfs(i, m-1);
        }
        for(int i = 0; i < m; i++){
            if(!_grid[0][i])     dfs(0, i);
            if(!_grid[n-1][i])   dfs(n-1, i);
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(!_grid[i][j]){
                    c++;
                    dfs(i, j);
                }
            }
        }
        return c;
    }
};