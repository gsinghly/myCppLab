// Time:  O(n + flights().size())
// Space: O(n)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector < vector < vector < int > > > g(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            g[u].push_back({v, w});
        }
        queue < vector < int > > q;
        q.push({src, 0, -1});
        int ans = INT_MAX;
        while (!q.empty()) {
            vector < int > s = q.front(); q.pop();
            int x = s[0];
            int y = s[1];
            int z = s[2];
            if (x == dst) {
                ans = min(ans, y);
                continue;
            }
            for (auto it : g[x]) {
                if (z + 1 <= K && y + it[1] < ans)
                    q.push({it[0], it[1] + y, z + 1});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
