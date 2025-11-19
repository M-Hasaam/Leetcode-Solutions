class Solution {
    using P = pair<double, int>;

public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<vector<P>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            graph[edge[0]].push_back({succProb[i], edge[1]});
            graph[edge[1]].push_back({succProb[i], edge[0]});
        }

        priority_queue<P, vector<P>> pq;
        vector<double> prob(n, 0);

        pq.push({1, start_node});
        prob[start_node] = 1;

        while (!pq.empty()) {
            auto [P, u] = pq.top();
            pq.pop();

            if (P < prob[u])
                continue;

            if (u == end_node)
                return prob[u];

            for (auto [nxt_P, nxt] : graph[u]) {
                if (prob[nxt] < P * nxt_P) {
                    prob[nxt] = P * nxt_P;

                    pq.push({prob[nxt], nxt});
                }
            }
        }

        return prob[end_node];
    }
};