class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        double ans = 0;
        priority_queue<pair<double, int>> q;
        q.push({1, start});
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n, 0);
        prob[start] = 1;
        while (!q.empty()) {
            int pos = q.top().second;
            double count = q.top().first;
            q.pop();
            if (pos == end)
                ans = max(ans, count);
            for (auto i : adj[pos]) {
                if (count * i.second > prob[i.first]) {
                    prob[i.first] = (double)count * i.second;
                    q.push({prob[i.first], i.first});
                }
            }
        }
        return ans;
    }
};