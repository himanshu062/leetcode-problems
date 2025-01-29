class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                return edge;
            } else {
                parent[pu] = pv;
            }
        }

        return {};
    }
};